#include <iostream>
#include "fix.h"

int wmain (int argc, wchar_t** argv)
{
    argc--;
    argv++;

    if (argc < 1)
    {
        std::wcerr << L"Must have atleast 1 argument";
        return -1;
    }

    std::wstring in = argv[0];
    std::wstring out;

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
        tuftmf::fix_file(in, out);

        _wrename(out.c_str(), in.c_str());
    }
    else if (argc == 2)
    {
        out = argv[1];

        std::wcout << L"in:" << in << L"\nout:" << out << L'\n';
        tuftmf::fix_file(in, out);
    }
    else
    {
        std::wcerr << L"Too many arguments";
        return -1;
    }


    return 0;
}
