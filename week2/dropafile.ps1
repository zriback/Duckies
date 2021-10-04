$path = "C:\Users\zacha\Desktop\newfile.txt"
New-Item -Path $path -ItemType File
"You have been HACKED" | Out-File -FilePath $path