#include "CurrentDesktopNotifier.h"
#include <iostream>
#include <KDE/KWindowSystem>


CurrentDesktopNotifier::CurrentDesktopNotifier (int & argc, char ** argv)
    : QApplication (argc, argv)
{
  std::cout << KWindowSystem::currentDesktop() << std::endl;
  connect(KWindowSystem::self(), SIGNAL(currentDesktopChanged(int)), this, SLOT(currentDesktopChanged(int)));
}

CurrentDesktopNotifier::~CurrentDesktopNotifier()
{

}

void CurrentDesktopNotifier::currentDesktopChanged(int desktop)
{
  std::cout << desktop << std::endl;
}
