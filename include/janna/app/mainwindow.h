#pragma once
#include <qaction.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qtmetamacros.h>
#include <spdlog/spdlog.h>

#include <QAction>
#include <QCloseEvent>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

namespace janna {
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    std::shared_ptr<spdlog::logger> log;

private:
    QMenuBar *m_menubar{nullptr};

    QMenu   *m_file{nullptr};
    QAction *act_file_new{nullptr};
    QAction *act_file_open{nullptr};
    QAction *act_file_save{nullptr};
    QAction *act_file_save_as{nullptr};
    QAction *act_file_restore{nullptr};
    QAction *act_file_print_preview{nullptr};
    QAction *act_file_print{nullptr};
    QAction *act_file_close{nullptr};
    QAction *act_file_exit{nullptr};

    QMenu   *m_edit{nullptr};
    QAction *act_edit_undo{nullptr};
    QAction *act_edit_redo{nullptr};
    QAction *act_edit_cut{nullptr};
    QAction *act_edit_copy{nullptr};
    QAction *act_edit_paste{nullptr};
    QAction *act_edit_delete{nullptr};
    QAction *act_edit_select_all{nullptr};
    QAction *act_edit_toggle_comment_line{nullptr};
    QAction *act_edit_toggle_comment_block{nullptr};
    QAction *act_edit_insert_date_time{nullptr};
    QAction *act_edit_sort{nullptr};
    QAction *act_edit_perferences{nullptr};

    QMenu   *m_view{nullptr};
    QAction *act_view_toolbar{nullptr};
    QAction *act_view_menubar{nullptr};
    QAction *act_view_statusbar{nullptr};
    QAction *act_view_sidebar{nullptr};
    QAction *act_view_bottom_panel{nullptr};
    QAction *act_view_minimap{nullptr};
    QAction *act_view_full_screen{nullptr};
    QAction *act_view_word_wrap{nullptr};
    QAction *act_view_font_zoom_in{nullptr};
    QAction *act_view_font_zoom_out{nullptr};
    QAction *act_view_font_zoom_default{nullptr};
    QAction *act_view_merge_line{nullptr};
    QAction *act_view_language_highlight{nullptr};

    QMenu   *m_search{nullptr};
    QAction *act_search_find{nullptr};
    QAction *act_search_find_next{nullptr};
    QAction *act_search_find_prev{nullptr};
    QAction *act_search_replace{nullptr};
    QAction *act_search_goto_line{nullptr};

    QMenu   *m_tool{nullptr};
    QAction *act_tool_spell_checker{nullptr};
    QAction *act_tool_auto_spell_checker{nullptr};
    QAction *act_tool_setting_language{nullptr};
    QAction *act_tool_statistics{nullptr};

    QMenu   *m_doc{nullptr};
    QAction *act_doc_save_all{nullptr};
    QAction *act_doc_close_all{nullptr};
    QAction *act_doc_prev{nullptr};
    QAction *act_doc_next{nullptr};
    QAction *act_doc_move_to_new_window{nullptr};

    QMenu   *m_help{nullptr};
    QAction *act_help_content{nullptr};
    QAction *act_help_keys{nullptr};
    QAction *act_help_about{nullptr};

private:
    void init();
    void init_menu_file();
    void init_menu_edit();
    void init_menu_view();
    void init_menu_search();
    void init_menu_tool();
    void init_menu_doc();
    void init_menu_help();

public Q_SLOTS:
    void on_act_file_new_triggered();
    void on_act_file_open_triggered();
    void on_act_file_save_triggered();
    void on_act_file_save_as_triggered();
    void on_act_file_restore_triggered();
    void on_act_file_print_preview_triggered();
    void on_act_file_print_triggered();
    void on_act_file_close_triggered();
    void on_act_file_exit_triggered();

    void on_act_edit_undo_triggered();
    void on_act_edit_redo_triggered();
    void on_act_edit_cut_triggered();
    void on_act_edit_copy_triggered();
    void on_act_edit_paste_triggered();
    void on_act_edit_delete_triggered();
    void on_act_edit_select_all_triggered();
    void on_act_edit_toggle_comment_line_triggered();
    void on_act_edit_toggle_comment_block_triggered();
    void on_act_edit_insert_date_time_triggered();
    void on_act_edit_sort_triggered();
    void on_act_edit_perferences_triggered();

    void on_act_view_toolbar_triggered(bool checked);
    void on_act_view_menubar_triggered(bool checked);
    void on_act_view_statusbar_triggered(bool checked);
    void on_act_view_sidebar_triggered(bool checked);
    void on_act_view_bottom_panel_triggered(bool checked);
    void on_act_view_minimap_triggered(bool checked);
    void on_act_view_full_screen_triggered(bool checked);
    void on_act_view_word_wrap_triggered(bool checked);
    void on_act_view_font_zoom_in_triggered();
    void on_act_view_font_zoom_out_triggered();
    void on_act_view_font_zoom_default_triggered();
    void on_act_view_merge_line_triggered();
    void on_act_view_language_highlight_triggered();

    void on_act_search_find_triggered();
    void on_act_search_find_next_triggered();
    void on_act_search_find_prev_triggered();
    void on_act_search_replace_triggered();
    void on_act_search_goto_line_triggered();

    void on_act_tool_spell_checker_triggered();
    void on_act_tool_auto_spell_checker_triggered(bool checked);
    void on_act_tool_setting_language_triggered();
    void on_act_tool_statistics_triggered();

    void on_act_doc_save_all_triggered();
    void on_act_doc_close_all_triggered();
    void on_act_doc_prev_triggered();
    void on_act_doc_next_triggered();
    void on_act_doc_move_to_new_window_triggered();

    void on_act_help_content_triggered();
    void on_act_help_keys_triggered();
    void on_act_help_about_triggered();
};
};  // namespace janna
