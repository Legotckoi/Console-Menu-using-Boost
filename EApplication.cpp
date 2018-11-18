#include "EApplication.h"

#include <iostream>

EApplication::EApplication(int argc, const char **argv)
{
    // Добавляем пункты меню
    m_desc.add_options()
            ("help", "produce help message")  // Вызов help справки
            ("input-file,i",  po::value<fs::path>(&m_inputFilePath)->composing(), "set input file path")              // Входной файл, можно записать либо --input-file, либо -i
            ("output-file,o", po::value<fs::path>(&m_outputFilePath)->composing(), "set output file path")            // Выходной файл
            ("block-size,b",  po::value<size_t>(&m_blockSize)->default_value(1024 * 1024), "set block size in bytes") // Размер блока
            ;
    po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
    po::notify(m_vm);
}

int EApplication::exec()
{
    // Если есть запрос на справку
    if (m_vm.count("help"))
    {
        // То выводим описание меню
        std::cout << m_desc << std::endl;
        return 1;
    }

    // Если были введены как минимум входной и выходной параметры
    if (m_vm.count("input-file") && m_vm.count("output-file"))
    {
        // то делаем инициализацию программы, но в данном случае только выводим информацию о введённых параметрах
        std::cout << m_inputFilePath << '\t' << m_outputFilePath << '\t' << m_blockSize << std::endl;
    }
    else
    {
        // В противном случае предлагаем посмотреть справку
        std::cout << "Please, use --help option for information" << std::endl;
        return 1;
    }

    // ToDo something
    // Здесь можем поместить в цикле while() или for(;;) логику программы

    return 0;
}
