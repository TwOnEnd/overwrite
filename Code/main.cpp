#include "main.h"
namespace exe {
	void copyFiles() {
		tools::checkFile();
		auto worldName = tools::getParameter("level-name");
		auto worldDir = "worlds\\" + worldName;
		auto infoTXT = "worlds\\info.txt";
		std::filesystem::copy(worldDir,
							  OVERWRITE_DIR + worldName,
							  std::filesystem::copy_options::recursive);
		std::filesystem::copy(infoTXT, OVERWRITE_DIR,
							  std::filesystem::copy_options::recursive);
		Sleep(500);
		std::filesystem::remove(infoTXT);
		std::filesystem::remove_all(worldDir);
		std::filesystem::rename("worlds\\_" + worldName, worldDir);
		Sleep(500);
	}
}

int main() {
	using namespace exe;
	copyFiles();
	system(tools::getParameter("process-name").c_str());
	return 0;
}
