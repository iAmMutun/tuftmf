#include <iostream>
#include "tuftmf/stream.h"

int wmain (int argc, wchar_t** argv)
{
    argc--;
    argv++;

    if (argc < 1)
    {
        std::wcerr << L"Must have atleast 1 argument";
        return -1;
    }

    int count = 0;
    tuftmf::set_fix_counter
    ([&count] (uint16_t a, uint16_t b) {
        count++;
        std::wcout << L'!';//<< std::showbase << std::hex << a << '>' << b;
    });

    std::wstring in = argv[0];
    std::wstring out;

    bool overwrite = false;

    if (argc == 1)
    {
        std::wcout << L"Overwrite input file? <y/n> : ";
        wchar_t prompt;
        std::wcin >> prompt;
        switch (prompt)
        {
        case L'N':
        case L'n':
        case L'F':
        case L'f':
        case L'0':
            std::wcout << L"Canceled";
            return 0;
        }

        wchar_t tmp[L_tmpnam_s];
        _wtmpnam_s(tmp);
        out = tmp;
        std::wcout << L"in:" << in << L"\nout:" << in << L'\n';
        overwrite = true;
    }
    else if (argc == 2)
    {
        out = argv[1];
        std::wcout << L"in:" << in << L"\nout:" << out << L'\n';
    }
    else
    {
        std::wcerr << L"Too many arguments";
        return -1;
    }

    tuftmf::ifstream fsin(in);
    tuftmf::ofstream fsout(out);

    if (fsin.fail())
    {
        std::wcerr << L"Error opening input file";
        return -1;
    }
    if (fsout.fail())
    {
        std::wcerr << L"Error opening output file";
        return -1;
    }

    tuftmf::fix(fsin, fsout);

    if (overwrite)
        _wrename(out.c_str(), in.c_str());


    if (count > 0)
        std::wcout << L'\n';
    std::wcout << L"fixed:" << count << std::endl;

    return 0;
}
