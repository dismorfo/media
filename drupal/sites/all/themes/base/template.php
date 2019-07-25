<?php

/**
 * Create a ZIP from source
 */
class HZip 
{ 
  /** 
   * Add files and sub-directories in a folder to zip file. 
   * @param string $folder 
   * @param ZipArchive $zipFile 
   * @param int $exclusiveLength Number of text to be exclusived from the file path. 
   */ 
  private static function folderToZip($folder, &$zipFile, $exclusiveLength) { 
    $handle = opendir($folder); 
    while (false !== $f = readdir($handle)) { 
      if ($f != '.' && $f != '..' && $f != '.git') { 
        $filePath = "$folder/$f"; 
        // Remove prefix from file path before add to zip. 
        $localPath = substr($filePath, $exclusiveLength); 
        if (is_file($filePath)) { 
          $zipFile->addFile($filePath, $localPath); 
        } elseif (is_dir($filePath)) { 
          // Add sub-directory. 
          $zipFile->addEmptyDir($localPath); 
          self::folderToZip($filePath, $zipFile, $exclusiveLength); 
        } 
      } 
    } 
    closedir($handle); 
  } 

  /** 
   * Zip a folder (include itself). 
   * Usage: 
   *   HZip::zipDir('/path/to/sourceDir', '/path/to/out.zip'); 
   * 
   * @param string $sourcePath Path of directory to be zip. 
   * @param string $outZipPath Path of output zip file. 
   */ 
  public static function zipDir($sourcePath, $outZipPath) 
  { 
    $pathInfo = pathInfo($sourcePath); 
    $parentPath = $pathInfo['dirname']; 
    $dirName = $pathInfo['basename']; 

    $z = new ZipArchive(); 
    $z->open($outZipPath, ZIPARCHIVE::CREATE); 
    $z->addEmptyDir($dirName); 
    self::folderToZip($sourcePath, $z, strlen("$parentPath/")); 
    $z->close(); 
  } 
} 

/**
 * Implements hook_preprocess_html().
 */
function projects_preprocess_html() {
}

/**
 * Preprocessor for theme('page').
 */
function projects_preprocess_page(&$vars) {
  global $user;
  if (!$user->uid && !(arg(0) == 'user' && !is_numeric(arg(1)))) {
    $vars['user_login_block'] = drupal_get_form('user_login_block');
  }
}

/**
 * Preprocessor for theme('node').
 */
function projects_views_pre_render(&$view) {
  if (
    $view->name == 'projects_list'
 || $view->name == 'modules_list'
 || $view->name == 'themes_list'
 || $view->name == 'profiles_list' 
 || $view->name == 'features_list' 
 || $view->name == 'distributions_list' 
 ) {
    
    global $theme_path;
    
    $zips_root = DRUPAL_ROOT . '/sites/all/projects/files';
    
    $source_root = DRUPAL_ROOT . '/sites/all/projects/source';  
    
    foreach ($view->result as $result) {
    
      $repo_url = isset($result->field_field_repository) ? $result->field_field_repository[0]['rendered']['#markup'] : NULL;
      
      $name = $result->field_field_project_name[0]['raw']['safe_value'];
      
      $project_name = str_replace(' ', '_', strtolower($name));
      
      $info_path = realpath($source_root . '/' . $project_name . '/' . $project_name . '.info');
      
      if (file_exists($info_path)) {
      
        $info = drupal_parse_info_file($info_path);
        
        if ($info) {
          
          $zip_filename = $project_name .  ( isset($info['version']) ? '-' . $info['version'] : '') . '.zip';
          
          $zip_path = $zips_root . '/' . $zip_filename;
          
          if (file_exists($zip_path)) {
            $result->field_field_project_name[0]['rendered']['#markup'] = l($name . ( isset($info['version']) ? ' ' . $info['version'] : ''), '/sites/all/projects/files/' . $zip_filename , array('absolute' => true, 'attributes' => array('title' => $info['description'])));
          }
          else {
          
            dpm(realpath($source_root . '/' . $project_name));
            dpm($zip_path);            
          
            HZip::zipDir(realpath($source_root . '/' . $project_name), $zip_path);
            
            if (file_exists($zip_path)) {
              $result->field_field_project_name[0]['rendered']['#markup'] = l($name . ( isset($info['version']) ? ' ' . $info['version'] : ''), '/sites/all/projects/files/' . $zip_filename , array('absolute' => true, 'attributes' => array('title' => $info['description'])));
            }
            
          }
          
          preg_match('/\/svn\/|\.git$/', $repo_url, $matches);
          
          $repo_path = in_array('/svn/', $matches) ? 'svn co ' . $repo_url . ' ' . $project_name: ( in_array('.git', $matches) ? 'git clone ' .  $repo_url : $repo_url);
          
          $result->field_field_repository[0]['rendered']['#markup'] = $repo_path;
        }
      }
    }
  }
}
