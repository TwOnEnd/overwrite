#ifndef MAIN_H
#define MAIN_H
// Windows ͷ�ļ�
#include <Windows.h>
// C++��׼�� ͷ�ļ�
#include <iostream>
#include <string>
#include <filesystem>
#include <io.h>
#include <direct.h>
// �����ļ�
#include "config.h"

#define OVERWRITE_DIR "BackupHelper\\overwrite\\"
namespace exe {
	namespace tools {
		void checkFile() {
			if(_access(OVERWRITE_DIR, 0) == -1) {
				_mkdir(OVERWRITE_DIR);
			} else {
				std::filesystem::remove_all(OVERWRITE_DIR);
				Sleep(500);
				_mkdir(OVERWRITE_DIR);
				Sleep(500);
			}
		}

		auto getParameter(std::string str) {
			Config config("server.properties");
			std::string parameter = config.Read<std::string>(str);
			return parameter;
		}
	}
}
#endif // !MAIN_H