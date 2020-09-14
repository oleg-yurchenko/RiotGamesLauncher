#include "sciter-x.h"
#include "sciter-x-window.hpp"

class frame : public sciter::window {
public: 
	frame() : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG) {}
};

#include "resources.cpp"

int uimain(std::function<int()> run) {
	sciter::archive::instance().open(aux::elements_of(resources));

	sciter::om::hasset<frame> pwin = new frame();

	pwin->load(WSTR("this://app/menu.htm"));

	pwin->expand();

	return run();
}