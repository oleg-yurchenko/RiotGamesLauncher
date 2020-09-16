#include "sciter-x.h"
#include "sciter-x-window.hpp"

//Change this to your path on your computer
const std::string clientPath = "\"C:\\Riot Games\\Riot Client\"";

//Constants to be used to shorten string when launching Riot Client Services
const std::string clientProgram = "RiotClientServices.exe";
const std::string param1 = " --launch-product=";
const std::string param2 = " --launch-patchline=";


//Create the Sciter window
class frame : public sciter::window {
public: 
	//constructor calls the sciter window function
	frame() : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG) {}

	//function to launch the games after clicking the button handled in menu.tis
	int launch(std::string gameVars) { 
		int complete = 0;
		std::string gameName;
		std::string gamePatch;
		if (gameVars.std::string::find("lol") != std::string::npos) {
			gameName = "league_of_legends";
			complete++;
		}
		else if (gameVars.std::string::find("val") != std::string::npos) {
			gameName = "valorant";
			complete++;
		}
		else if (gameVars.std::string::find("lor") != std::string::npos) {
			gameName = "bacon";
			complete++;
		}

		if (gameVars.std::string::find("live") != std::string::npos) {
			gamePatch = "live";
			complete++;
		}
		else if (gameVars.std::string::find("pbe") != std::string::npos) {
			gamePatch = "pbe";
			complete++;
		}
		if (complete == 2) {
			STARTUPINFO si;
			PROCESS_INFORMATION pi;

			ZeroMemory(&si, sizeof(si));
			si.cb = sizeof(si);
			ZeroMemory(&pi, sizeof(pi));

			std::string appArgs = "\"C:\\Riot Games\\Riot Client\\RiotClientServices.exe\"" + param1 + gameName + param2 + gamePatch;
			LPSTR pAppArgs = &appArgs.front();

			if (CreateProcess(NULL, pAppArgs, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
				WaitForSingleObject(pi.hProcess, INFINITE);
				CloseHandle(pi.hProcess);
				CloseHandle(pi.hThread);
			}
			else {
				MessageBox(NULL, "Error launching RiotClientServices.exe", "ERROR", MB_OK);
			}

			//system(("cd " + clientPath + " & " + clientProgram + param1 + gameName + param2 + gamePatch).c_str());
			return 0;
		}
		else {
			return 1;
		}
	};

	//Create SOM passport to add the launch function
	SOM_PASSPORT_BEGIN(frame)
		SOM_FUNCS(SOM_FUNC(launch))
	SOM_PASSPORT_END
};

#include "resources.cpp"

int uimain(std::function<int()> run) {
	sciter::archive::instance().open(aux::elements_of(resources));

	sciter::om::hasset<frame> pwin = new frame();

	pwin->load(WSTR("this://app/menu.htm"));

	pwin->expand();

	return run();
}