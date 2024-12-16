#include "janna/app/mainwindow.h"

#include <qaction.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qpixmap.h>

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QPixmap>

#include "janna/util/log_util.h"

namespace janna {
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->log = LogUtil::getLogger("app");

    QMenuBar *menubar = this->menuBar();
    QMenu    *file    = menubar->addMenu("文件");
    QAction  *act_new = file->addAction("新建");
    act_new->setIcon(QPixmap(":icon/new_16"));
}

void MainWindow::closeEvent(QCloseEvent *event) {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna is closing..."));
    // 如果你想阻止窗口关闭，取消事件
    // event->ignore();

    event->accept();
}

}  // namespace janna