#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>

class CurrentDesktopNotifier : public QApplication
{
  Q_OBJECT
public:
  CurrentDesktopNotifier (int & argc, char ** argv);
  ~CurrentDesktopNotifier();

public slots:
  void currentDesktopChanged(int desktop);
};


#endif // MAINWINDOW_H
