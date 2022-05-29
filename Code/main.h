#ifndef MAIN_H
#define MAIN_H
// Windows 头文件
#include <Windows.h>
// C++标准库 头文件
#include <iostream>
#include <string>
#include <filesystem>
#include <io.h>
#include <thread>
#include <direct.h>
// 其他文件
#include "config.h"
// 防报错
#pragma warning(disable:4996)
#pragma warning(disable:4267)
#pragma warning(disable:4244)

#define OVERWRITE_DIR "backup\\overwrite\\"
namespace exe {
	namespace tools {
		template<typename OS, typename T>
		void ostr(OS &o, T t) {
			o << t;
		}
		template<typename... ARG>
		auto myString(ARG... arg)->std::string {
			std::ostringstream os;
			int arr[] = { (ostr(os,arg),0)... };
			return os.str();
		}

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
			std::string parameter;
			parameter = config.Read<std::string>(str);
			return parameter;
		}
	}
}
#endif // !MAIN_H