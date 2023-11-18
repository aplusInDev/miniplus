#include "main.h"

void file_filler(string path, int start, int end)
{
    fstream file;
    (void)start, (void)end;

    file.open(path, ios::app);
    if (file.is_open())
    {
        file << start + rand() % (end - start + 1) << endl;
        file.close();
    }
    else
    {
        cout << "error: file '" << path << "' not found" << endl;
    }
}
vector<int> file_reader(string path)
{
    int value;
    vector<int> meteo_v;
    ifstream meteo_f;

    try
    {
        meteo_f.open(path);
        if (meteo_f.is_open())
        {
            while (meteo_f >> value)
            {
                meteo_v.push_back(value);
            }
            if (meteo_v.size() < 3)
            {
                for (size_t i = meteo_v.size(); i < 3; i++)
                    meteo_v.push_back(0);
            }
            meteo_f.close();
        }
        else
        {
            meteo_v = {0, 0, 0};
            throw(path);
        }
    }
    catch (string path)
    {
        cout << "error: file '" << path << "' not found" << endl;
    }

    return (meteo_v);
}
vector<int> generate_temp()
{
    vector<int> temp_v;

    file_filler("meteo/temp.txt", 5, 42);
    temp_v = file_reader("meteo/temp.txt");
    return (temp_v);
}
vector<int> generate_hyg()
{
    vector<int> hyg_v;

    file_filler("meteo/hyg.txt", 45, 62);
    hyg_v = file_reader("meteo/hyg.txt");
    return (hyg_v);
}
vector<int> generate_press()
{
    vector<int> press_v;

    file_filler("meteo/press.txt", 1012, 1033);
    press_v = file_reader("meteo/press.txt");
    return (press_v);
}