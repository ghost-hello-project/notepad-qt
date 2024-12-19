#include "janna/app/mainwindow.h"

#include <qaction.h>
#include <qkeysequence.h>
#include <qmainwindow.h>
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
    init_toolbar();
}

void MainWindow::init_menu_file() {
    m_file       = m_menubar->addMenu("文件(&F)");
    act_file_new = m_file->addAction("新建");
    act_file_new->setIcon(QPixmap(":icon/new_16"));
    act_file_new->setObjectName("act_file_new");
    act_file_new->setShortcut(QKeySequence("Ctrl+N"));

    act_file_open = m_file->addAction("打开");
    act_file_open->setObjectName("act_file_open");
    act_file_open->setIcon(QPixmap(":icon/open_16"));
    act_file_open->setShortcut(QKeySequence("Ctrl+O"));

    m_file->addSeparator();

    act_file_save = m_file->addAction("保存");
    act_file_save->setIcon(QPixmap(":icon/save_16"));
    act_file_save->setObjectName("act_file_save");
    act_file_save->setShortcut(QKeySequence("Ctrl+S"));

    act_file_save_as = m_file->addAction("另存为");
    act_file_save_as->setIcon(QPixmap(":icon/save_as_16"));
    act_file_save_as->setObjectName("act_file_save_as");
    act_file_save_as->setShortcut(QKeySequence("Ctrl+Shift+S"));

    act_file_restore = m_file->addAction("恢复");
    act_file_restore->setObjectName("act_file_restore");

    m_file->addSeparator();

    act_file_print_preview = m_file->addAction("打印预览");
    act_file_print_preview->setObjectName("act_file_print_preview");

    act_file_print = m_file->addAction("打印");
    act_file_print->setObjectName("act_file_print");

    m_file->addSeparator();

    act_file_close = m_file->addAction("关闭");
    act_file_close->setIcon(QPixmap(":icon/close_16"));
    act_file_close->setObjectName("act_file_close");
    act_file_close->setShortcut(QKeySequence("Ctrl+W"));

    act_file_exit = m_file->addAction("退出");
    act_file_exit->setIcon(QPixmap(":icon/exit_16"));
    act_file_exit->setObjectName("act_file_exit");
    act_file_exit->setShortcut(QKeySequence("Ctrl+Q"));
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
    m_edit = m_menubar->addMenu("编辑(&E)");

    act_edit_undo = m_edit->addAction("撤销");
    act_edit_undo->setIcon(QPixmap(":icon/undo_16"));
    act_edit_undo->setObjectName("act_edit_undo");
    act_edit_undo->setShortcut(QKeySequence("Ctrl+Z"));

    act_edit_redo = m_edit->addAction("重做");
    act_edit_redo->setIcon(QPixmap(":icon/redo_16"));
    act_edit_redo->setObjectName("act_edit_redo");
    act_edit_redo->setShortcut(QKeySequence("Ctrl+Y"));

    m_edit->addSeparator();

    act_edit_cut = m_edit->addAction("剪切");
    act_edit_cut->setIcon(QPixmap(":icon/cut_16"));
    act_edit_cut->setObjectName("act_edit_cut");
    act_edit_cut->setShortcut(QKeySequence("Ctrl+X"));

    act_edit_copy = m_edit->addAction("复制");
    act_edit_copy->setIcon(QPixmap(":icon/copy_16"));
    act_edit_copy->setObjectName("act_edit_copy");
    act_edit_copy->setShortcut(QKeySequence("Ctrl+C"));

    act_edit_paste = m_edit->addAction("粘帖");
    act_edit_paste->setIcon(QPixmap(":icon/paste_16"));
    act_edit_paste->setObjectName("act_edit_paste");
    act_edit_paste->setShortcut(QKeySequence("Ctrl+V"));

    act_edit_delete = m_edit->addAction("删除");
    act_edit_delete->setObjectName("");

    m_edit->addSeparator();

    act_edit_select_all = m_edit->addAction("全部选中");
    act_edit_select_all->setObjectName("act_edit_select_all");
    act_edit_select_all->setShortcut(QKeySequence("Ctrl+A"));

    m_edit->addSeparator();

    act_edit_toggle_comment_line = m_edit->addAction("切换注释");
    act_edit_toggle_comment_line->setObjectName("act_edit_toggle_comment_line");
    act_edit_toggle_comment_line->setShortcut(QKeySequence("Ctrl+/"));

    act_edit_toggle_comment_block = m_edit->addAction("切换注视块");
    act_edit_toggle_comment_block->setObjectName("act_edit_toggle_comment_block");
    act_edit_toggle_comment_block->setShortcut(QKeySequence("Ctrl+Shift+/"));

    m_edit->addSeparator();

    act_edit_insert_date_time = m_edit->addAction("插入日期和时间...");
    act_edit_insert_date_time->setObjectName("act_edit_insert_date_time");
    act_edit_insert_date_time->setShortcut(QKeySequence("F5"));

    m_edit->addSeparator();

    act_edit_sort = m_edit->addAction("排序");
    act_edit_sort->setObjectName("act_edit_sort");
    act_edit_sort->setShortcut(QKeySequence("F10"));

    m_edit->addSeparator();

    act_edit_perferences = m_edit->addAction("首选项...");
    act_edit_perferences->setIcon(QPixmap(":icon/perferences_16"));
    act_edit_perferences->setObjectName("act_edit_perferences");
}

void MainWindow::on_act_edit_undo_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_undo"));
}
void MainWindow::on_act_edit_redo_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_redo"));
}
void MainWindow::on_act_edit_cut_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_cut"));
}
void MainWindow::on_act_edit_copy_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_copy"));
}
void MainWindow::on_act_edit_paste_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_paste"));
}
void MainWindow::on_act_edit_delete_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_delete"));
}
void MainWindow::on_act_edit_select_all_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_select_all"));
}
void MainWindow::on_act_edit_toggle_comment_line_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_toggle_comment_line"));
}
void MainWindow::on_act_edit_toggle_comment_block_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_toggle_comment_block"));
}
void MainWindow::on_act_edit_insert_date_time_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_insert_date_time"));
}
void MainWindow::on_act_edit_sort_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_sort"));
}
void MainWindow::on_act_edit_perferences_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_edit_perferences"));
}

void MainWindow::init_menu_view() {
    m_view = m_menubar->addMenu("查看(&V)");

    act_view_toolbar = m_view->addAction("工具栏");
    act_view_toolbar->setObjectName("act_view_toolbar");
    act_view_toolbar->setCheckable(true);
    act_view_toolbar->setChecked(true);

    act_view_menubar = m_view->addAction("菜单栏");
    act_view_menubar->setObjectName("act_view_menubar");
    act_view_menubar->setCheckable(true);
    act_view_menubar->setChecked(true);

    act_view_statusbar = m_view->addAction("状态栏");
    act_view_statusbar->setObjectName("act_view_statusbar");
    act_view_statusbar->setCheckable(true);
    act_view_statusbar->setChecked(true);

    act_view_sidebar = m_view->addAction("侧边栏");
    act_view_sidebar->setShortcut(QKeySequence("F9"));
    act_view_sidebar->setObjectName("act_view_sidebar");
    act_view_sidebar->setCheckable(true);
    act_view_sidebar->setChecked(false);

    act_view_bottom_panel = m_view->addAction("底部面板");
    act_view_bottom_panel->setShortcut(QKeySequence("Ctrl+F9"));
    act_view_bottom_panel->setObjectName("act_view_bottom_panel");
    act_view_bottom_panel->setCheckable(true);
    act_view_bottom_panel->setChecked(false);

    act_view_minimap = m_view->addAction("缩略图");
    act_view_minimap->setShortcut(QKeySequence("F12"));
    act_view_minimap->setObjectName("act_view_minimap");
    act_view_minimap->setCheckable(true);
    act_view_minimap->setChecked(false);

    m_view->addSeparator();

    act_view_full_screen = m_view->addAction("全屏");
    act_view_full_screen->setShortcut(QKeySequence("F11"));
    act_view_full_screen->setObjectName("act_view_full_screen");

    m_view->addSeparator();

    act_view_word_wrap = m_view->addAction("单词换行");
    act_view_word_wrap->setShortcut(QKeySequence("Ctrl+R"));
    act_view_word_wrap->setObjectName("act_view_word_wrap");
    act_view_word_wrap->setCheckable(true);
    act_view_word_wrap->setChecked(true);

    m_view->addSeparator();

    act_view_font_zoom_in = m_view->addAction("文本放大");
    act_view_font_zoom_in->setShortcut(QKeySequence("Ctrl+="));
    act_view_font_zoom_in->setObjectName("act_view_font_zoom_in");

    act_view_font_zoom_out = m_view->addAction("文本缩小");
    act_view_font_zoom_out->setShortcut(QKeySequence("Ctrl+-"));
    act_view_font_zoom_out->setObjectName("act_view_font_zoom_out");

    act_view_font_zoom_default = m_view->addAction("文本默认大小");
    act_view_font_zoom_default->setShortcut(QKeySequence("Ctrl+0"));
    act_view_font_zoom_default->setObjectName("act_view_font_zoom_default");

    act_view_merge_line = m_view->addAction("合并行");
    act_view_merge_line->setShortcut(QKeySequence("Ctrl+J"));
    act_view_merge_line->setObjectName("act_view_merge_line");

    m_view->addSeparator();

    act_view_language_highlight = m_view->addAction("语法高亮...");
    act_view_language_highlight->setShortcut(QKeySequence("Ctrl+Shift+H"));
    act_view_language_highlight->setObjectName("act_view_language_highlight");
}

void MainWindow::on_act_view_toolbar_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_toolbar"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_toolbar"));
    }
}
void MainWindow::on_act_view_menubar_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_toolbar"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_toolbar"));
    }
}
void MainWindow::on_act_view_statusbar_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_statusbar"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_statusbar"));
    }
}
void MainWindow::on_act_view_sidebar_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_sidebar"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_sidebar"));
    }
}
void MainWindow::on_act_view_bottom_panel_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_bottom_panel"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_bottom_panel"));
    }
}
void MainWindow::on_act_view_minimap_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_minimap"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_minimap"));
    }
}
void MainWindow::on_act_view_full_screen_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_full_screen"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_full_screen"));
    }
}
void MainWindow::on_act_view_word_wrap_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_word_wrap"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not act_view_word_wrap"));
    }
}
void MainWindow::on_act_view_font_zoom_in_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_font_zoom_in"));
}
void MainWindow::on_act_view_font_zoom_out_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_font_zoom_out"));
}
void MainWindow::on_act_view_font_zoom_default_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_font_zoom_default"));
}
void MainWindow::on_act_view_merge_line_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_merge_line"));
}
void MainWindow::on_act_view_language_highlight_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_view_language_highlight"));
}

void MainWindow::init_menu_search() {
    m_search = m_menubar->addMenu("搜索(&S)");

    act_search_find = m_search->addAction("查找");
    act_search_find->setIcon(QPixmap(":icon/find_16"));
    act_search_find->setShortcut(QKeySequence("Ctrl+F"));
    act_search_find->setObjectName("act_search_find");

    act_search_find_next = m_search->addAction("查找下一个");
    act_search_find_next->setShortcut(QKeySequence("Ctrl+G"));
    act_search_find_next->setObjectName("act_search_find_next");

    act_search_find_prev = m_search->addAction("查找上一个");
    act_search_find_prev->setShortcut(QKeySequence("Ctrl+Shift+G"));
    act_search_find_prev->setObjectName("act_search_find_prev");

    m_search->addSeparator();

    act_search_replace = m_search->addAction("替换");
    act_search_replace->setIcon(QPixmap(":icon/replace_16"));
    act_search_replace->setShortcut(QKeySequence("Ctrl+H"));
    act_search_replace->setObjectName("act_search_replace");

    m_search->addSeparator();

    act_search_goto_line = m_search->addAction("跳到行...");
    act_search_goto_line->setShortcut(QKeySequence("Ctrl+I"));
    act_search_goto_line->setObjectName("act_search_goto_line");
}

void MainWindow::on_act_search_find_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_search_find"));
}
void MainWindow::on_act_search_find_next_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_search_find_next"));
}
void MainWindow::on_act_search_find_prev_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_search_find_prev"));
}
void MainWindow::on_act_search_replace_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_search_replace"));
}
void MainWindow::on_act_search_goto_line_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_search_goto_line"));
}

void MainWindow::init_menu_tool() {
    m_tool = m_menubar->addMenu("工具(&T)");

    act_tool_spell_checker = m_tool->addAction("拼写检查");
    act_tool_spell_checker->setIcon(QPixmap(":icon/spell_checker_16"));
    act_tool_spell_checker->setShortcut(QKeySequence("Shift+F7"));
    act_tool_spell_checker->setObjectName("act_tool_spell_checker");

    act_tool_auto_spell_checker = m_tool->addAction("自动拼写检查");
    act_tool_auto_spell_checker->setCheckable(true);
    act_tool_auto_spell_checker->setChecked(false);
    act_tool_auto_spell_checker->setObjectName("act_tool_auto_spell_checker");

    act_tool_setting_language = m_tool->addAction("设置语言...");
    act_tool_setting_language->setObjectName("act_tool_setting_language");

    m_tool->addSeparator();

    act_tool_statistics = m_tool->addAction("文档统计");
    act_tool_statistics->setObjectName("act_tool_statistics");
}

void MainWindow::on_act_tool_spell_checker_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_tool_spell"));
}
void MainWindow::on_act_tool_auto_spell_checker_triggered(bool checked) {
    if (checked) {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("auto check spell"));
    } else {
        SPDLOG_LOGGER_DEBUG(log, fmt::format("not auto check spell"));
    }
}
void MainWindow::on_act_tool_setting_language_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_tool_setting_language"));
}
void MainWindow::on_act_tool_statistics_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_tool_statistics"));
}

void MainWindow::init_menu_doc() {
    m_doc = m_menubar->addMenu("文档(&D)");

    act_doc_save_all = m_doc->addAction("全部保存");
    act_doc_save_all->setIcon(QPixmap(":icon/save_16"));
    act_doc_save_all->setShortcut(QKeySequence("Ctrl+Shift+L"));
    act_doc_save_all->setObjectName("act_doc_save_all");

    act_doc_close_all = m_doc->addAction("全部关闭");
    act_doc_close_all->setIcon(QPixmap(":icon/close_16"));
    act_doc_close_all->setShortcut(QKeySequence("Ctrl+Shift+W"));
    act_doc_close_all->setObjectName("act_doc_close_all");

    m_doc->addSeparator();

    act_doc_prev = m_doc->addAction("上一个文档");
    act_doc_prev->setShortcut(QKeySequence("Ctrl+ALt+Page UP"));
    act_doc_prev->setObjectName("act_doc_prev");

    act_doc_next = m_doc->addAction("下一个文档");
    act_doc_next->setShortcut(QKeySequence("Ctrl+ALt+Page Down"));
    act_doc_next->setObjectName("act_doc_next");

    m_doc->addSeparator();

    act_doc_move_to_new_window = m_doc->addAction("移动到新窗口");
    act_doc_move_to_new_window->setObjectName("act_doc_move_to_new_window");
}

void MainWindow::on_act_doc_save_all_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_doc_save_all"));
}
void MainWindow::on_act_doc_close_all_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_doc_close_all"));
}
void MainWindow::on_act_doc_prev_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_doc_prev"));
}
void MainWindow::on_act_doc_next_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_doc_next"));
}
void MainWindow::on_act_doc_move_to_new_window_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_doc_move_to_new_window"));
}

void MainWindow::init_menu_help() {
    m_help = m_menubar->addMenu("帮助(&H)");

    act_help_content = m_help->addAction("内容");
    act_help_content->setIcon(QPixmap(":icon/help_16"));
    act_help_content->setShortcut(QKeySequence("F1"));
    act_help_content->setObjectName("act_help_content");

    act_help_keys = m_help->addAction("快捷键");
    act_help_keys->setIcon(QPixmap(":icon/key_16"));
    act_help_keys->setObjectName("act_help_keys");

    act_help_about = m_help->addAction("关于");
    act_help_about->setIcon(QPixmap(":icon/about_16"));
    act_help_about->setObjectName("act_help_about");
}

void MainWindow::on_act_help_content_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_help_content"));
}
void MainWindow::on_act_help_keys_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_help_keys"));
}
void MainWindow::on_act_help_about_triggered() {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("act_help_about"));
}

void MainWindow::init_toolbar() {
    m_toolbar = new QToolBar();
    m_toolbar->setMovable(false);
    addToolBar(m_toolbar);
    m_toolbar->addAction(act_file_new);
    m_toolbar->addAction(act_file_open);
    m_toolbar->addAction(act_file_save);
    m_toolbar->addAction(act_file_save_as);
    m_toolbar->addSeparator();
    m_toolbar->addAction(act_edit_undo);
    m_toolbar->addAction(act_edit_redo);
    m_toolbar->addSeparator();
    m_toolbar->addAction(act_edit_cut);
    m_toolbar->addAction(act_edit_copy);
    m_toolbar->addAction(act_edit_paste);
    m_toolbar->addSeparator();
    m_toolbar->addAction(act_search_find);
    m_toolbar->addAction(act_search_replace);
}
}  // namespace janna