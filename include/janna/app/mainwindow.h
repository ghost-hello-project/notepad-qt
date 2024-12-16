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

    QMenu *m_view{nullptr};
    QMenu *m_search{nullptr};
    QMenu *m_tool{nullptr};
    QMenu *m_doc{nullptr};
    QMenu *m_help{nullptr};

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
};
};  // namespace janna
