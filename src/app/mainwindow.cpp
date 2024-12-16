#include "janna/app/mainwindow.h"

#include <qaction.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qobjectdefs.h>
#include <qpixmap.h>

#include <QPixmap>

#include "janna/util/log_util.h"

namespace janna {
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->log = LogUtil::getLogger("app");

    init();

    QMetaObject::connectSlotsByName(this);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna is closing..."));
    // 如果你想阻止窗口关闭，取消事件
    // event->ignore();

    event->accept();
}

void MainWindow::init() {
    resize(800, 600);

    m_menubar = menuBar();
    init_menu_file();
    init_menu_edit();
    init_menu_view();
    init_menu_search();
    init_menu_tool();
    init_menu_doc();
    init_menu_help();
}

void MainWindow::init_menu_file() {
    m_file       = m_menubar->addMenu("文件");
    act_file_new = m_file->addAction("新建");
    act_file_new->setIcon(QPixmap(":icon/new_16"));
    act_file_new->setObjectName("act_file_new");

    act_file_open = m_file->addAction("打开");
    act_file_open->setObjectName("act_file_open");

    m_file->addSeparator();

    act_file_save = m_file->addAction("保存");
    act_file_save->setObjectName("act_file_save");

    act_file_save_as = m_file->addAction("另存为");
    act_file_save_as->setObjectName("act_file_save_as");

    act_file_restore = m_file->addAction("恢复");
    act_file_restore->setObjectName("act_file_restore");

    m_file->addSeparator();

    act_file_print_preview = m_file->addAction("打印预览");
    act_file_print_preview->setObjectName("act_file_print_preview");

    act_file_print = m_file->addAction("打印");
    act_file_print->setObjectName("act_file_print");

    m_file->addSeparator();

    act_file_close = m_file->addAction("关闭");
    act_file_close->setObjectName("act_file_close");

    act_file_exit = m_file->addAction("退出");
    act_file_exit->setObjectName("act_file_exit");
}

void MainWindow::on_act_file_new_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file new"));
}

void MainWindow::on_act_file_open_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file open"));
}
void MainWindow::on_act_file_save_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file save"));
}
void MainWindow::on_act_file_save_as_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file save_as"));
}
void MainWindow::on_act_file_restore_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file restore"));
}
void MainWindow::on_act_file_print_preview_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file print_preview"));
}
void MainWindow::on_act_file_print_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file print"));
}
void MainWindow::on_act_file_close_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file close"));
}
void MainWindow::on_act_file_exit_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act file exit"));
}

void MainWindow::init_menu_edit() {
    m_edit = m_menubar->addMenu("编辑");

    act_edit_undo = m_edit->addAction("撤销");
    act_edit_redo = m_edit->addAction("重做");
    m_edit->addSeparator();
    act_edit_cut    = m_edit->addAction("剪切");
    act_edit_copy   = m_edit->addAction("复制");
    act_edit_paste  = m_edit->addAction("粘帖");
    act_edit_delete = m_edit->addAction("删除");
    m_edit->addSeparator();
    act_edit_select_all = m_edit->addAction("全部选中");
    m_edit->addSeparator();
    act_edit_toggle_comment_line  = m_edit->addAction("切换注释");
    act_edit_toggle_comment_block = m_edit->addAction("切换注视块");
    m_edit->addSeparator();
    act_edit_insert_date_time = m_edit->addAction("插入日期和时间...");
    m_edit->addSeparator();
    act_edit_sort = m_edit->addAction("排序");
    m_edit->addSeparator();
    act_edit_perferences = m_edit->addAction("首选项...");
}
void MainWindow::init_menu_view() {
    m_view = m_menubar->addMenu("查看");
}
void MainWindow::init_menu_search() {
    m_search = m_menubar->addMenu("搜索");
}
void MainWindow::init_menu_tool() {
    m_tool = m_menubar->addMenu("工具");
}
void MainWindow::init_menu_doc() {
    m_doc = m_menubar->addMenu("文档");
}
void MainWindow::init_menu_help() {
    m_help = m_menubar->addMenu("帮助");
}

}  // namespace janna