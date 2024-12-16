#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>

#include <QApplication>
#include <QIcon>
#include <QStyleFactory>
#include <QSysInfo>
#include <cstdlib>

#include "janna/app/mainwindow.h"
#include "janna/util/app_config.h"
#include "janna/util/log_util.h"

void exit();

using namespace janna;
int main(int argc, char *argv[]) {
    LogUtil::init(AppConfig::getInstance()->logLevel(), "../logs/app.log");
    std::shared_ptr<spdlog::logger> log = LogUtil::getLogger("app");
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna is running..."));

    QApplication a(argc, argv);
#ifdef Q_OS_WIN
    a.setWindowIcon(QIcon(":/logo/logo_32"));
#endif

    MainWindow w;
    w.show();

    auto result = QApplication::exec();
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna result code:{}", result));
    log->flush();
    spdlog::shutdown();
    exit();
    return result;
}

void exit() {
#ifdef Q_OS_WIN
    std::string exit_cmd = "taskkill /t /f /PID " + std::to_string(_getpid());
    system(exit_cmd.c_str());
#endif
}