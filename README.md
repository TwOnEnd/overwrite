# overwrite
This is the external exe program backuphelper.dll
## 使用方法
将 overwrite.exe 放入bds根目录下

然后前往 server.properties 文件,加入以下变量
start-program-name=xxx

xxx替换成启动服务器的名称

最后装载 BackupHelper插件

BackupHelper:https://github.com/TwOnEnd/BackupHelper

## 例如:

### 一.使用 LiteLoaderBDS 加载器

  main-program-name=bedrock_server_mod.exe
  
### 二.使用 .bat 启动服务器
  假如使用 mc_start.bat 启动服务器
  
  main-program-name=mc_start.bat
