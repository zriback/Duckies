$DesktopPath = [Environment]::GetFolderPath("Desktop")
$FileName = "Duckie File"
$FullPath = $DeskTopPath + "\"+ $FileName

$NumFiles = $args[0]
$Message = $args[1]

for ($i = 0; $i -lt $NumFiles; $i++){
    # New-Item -Path ($FullPath + $i) -ItemType File
    $Message | Out-File -FilePath ($FullPath + $i + ".txt")
}
