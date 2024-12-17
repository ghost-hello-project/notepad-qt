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

    act_view_toolbar = m_view->addAction("工具栏");
    act_view_toolbar->setCheckable(true);
    act_view_toolbar->setChecked(true);

    act_view_menubar = m_view->addAction("菜单栏");
    act_view_menubar->setCheckable(true);
    act_view_menubar->setChecked(true);

    act_view_statusbar = m_view->addAction("状态栏");
    act_view_statusbar->setCheckable(true);
    act_view_statusbar->setChecked(true);

    act_view_sidebar = m_view->addAction("侧边栏");
    act_view_sidebar->setCheckable(true);
    act_view_sidebar->setChecked(false);

    act_view_bottom_panel = m_view->addAction("底部面板");
    act_view_bottom_panel->setCheckable(true);
    act_view_bottom_panel->setChecked(false);

    act_view_minimap = m_view->addAction("缩略图");
    act_view_minimap->setCheckable(true);
    act_view_minimap->setChecked(false);

    m_view->addSeparator();

    act_view_full_screen = m_view->addAction("屏幕");

    m_view->addSeparator();

    act_view_word_wrap = m_view->addAction("单词换行");
    act_view_word_wrap->setCheckable(true);
    act_view_word_wrap->setChecked(true);

    m_view->addSeparator();

    act_view_font_zoom_in = m_view->addAction("文本放大");

    act_view_font_zoom_out = m_view->addAction("文本缩小");

    act_view_font_zoom_default = m_view->addAction("文本默认大小");

    act_view_merge_line = m_view->addAction("合并行");

    m_view->addSeparator();

    act_view_language_highlight = m_view->addAction("语言高亮...");
}
void MainWindow::init_menu_search() {
    m_search             = m_menubar->addMenu("搜索");
    act_search_find      = m_search->addAction("查找");
    act_search_find_next = m_search->addAction("查找下一个");
    act_search_find_prev = m_search->addAction("查找上一个");
    m_search->addSeparator();
    act_search_replace = m_search->addAction("替换");
    m_search->addSeparator();
    act_search_goto_line = m_search->addAction("跳到行...");
}
void MainWindow::init_menu_tool() {
    m_tool                 = m_menubar->addMenu("工具");
    act_tool_spell_checker = m_tool->addAction("拼写检查");

    act_tool_auto_spell_checker = m_tool->addAction("自动拼写检查");
    act_tool_auto_spell_checker->setCheckable(true);
    act_tool_auto_spell_checker->setChecked(false);

    act_tool_setting_language = m_tool->addAction("设置语言...");
    m_tool->addSeparator();
    act_tool_statistics = m_tool->addAction("文档统计");
}
void MainWindow::init_menu_doc() {
    m_doc             = m_menubar->addMenu("文档");
    act_doc_save_all  = m_doc->addAction("全比保存");
    act_doc_close_all = m_doc->addAction("全部关闭");
    m_doc->addSeparator();
    act_doc_prev = m_doc->addAction("上一个文档");
    act_doc_next = m_doc->addAction("下一个文档");
    m_doc->addSeparator();
    act_doc_move_to_new_window = m_doc->addAction("移动到新窗口");
}
void MainWindow::init_menu_help() {
    m_help           = m_menubar->addMenu("帮助");
    act_help_content = m_help->addAction("内容");
    act_help_keys    = m_help->addAction("快捷键");
    act_help_about   = m_help->addAction("关于");
}

}  // namespace janna