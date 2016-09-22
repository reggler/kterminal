#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QAction>
#include <KMainWindow>
#include "sessionstack.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QShortcut>
#include "session.h"

class QAction;
class KActionCollection;

class MainWindow : public KMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        KActionCollection* actionCollection() { return m_actionCollection; }

    public slots:
        void handleTerminalActivity(Terminal* terminal);
        void handleTerminalSilence(Terminal* terminal);
        void mySplitTopBottom();
        void mySplitLeftRight();

    signals:
        void windowClosed();

    private:
        SessionStack *m_sessionStack;
        KActionCollection* m_actionCollection;
        QWidget *centralWidget;
        QGridLayout *gridLayout;
        Session *m_session;
};

#endif
