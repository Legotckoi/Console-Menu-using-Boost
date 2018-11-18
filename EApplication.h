#ifndef MENU_EAPPLICATION_H
#define MENU_EAPPLICATION_H

#include <boost/program_options.hpp>
#include <boost/filesystem/fstream.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

class EApplication
{
public:
    explicit EApplication(int argc, const char** argv);

    int exec();

private:
    // Описание доступных опций меню
    po::options_description m_desc {"Allowed options"};
    po::variables_map m_vm; // контейнер для сохранения выбранных опций программы

    // Требуемые в программе переменные для работы с опциями меню
    size_t m_blockSize;
    fs::path m_inputFilePath;
    fs::path m_outputFilePath;
};


#endif //MENU_EAPPLICATION_H
