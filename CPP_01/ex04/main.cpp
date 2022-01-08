#include <iostream>
#include <fstream>

int check_arg(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Invalid argument" << std::endl;
        return 1;
    }
    return 0;
}

int check_ifstream(std::ifstream &read_file, std::string file_name)
{
    if (read_file.fail())
    {
        std::cerr << "Unable to find the file : " << file_name << std::endl;
        read_file.close();
        return 1;
    }
    return 0;
}

int check_ofstream(std::ofstream &write_file, std::ifstream &read_file, std::string file_name)
{
    if (write_file.fail())
    {
        std::cerr << "Faild to write the file.: " << file_name << std::endl;
        read_file.close();
        return 1;
    }
    return 0;
}

void write_replace_file(std::ifstream &read_file, std::ofstream &write_file, char **av)
{
    std::string to_find(av[2]);
    std::string replace(av[3]);
    std::string line;

    std::string::size_type pos;
    while (getline(read_file, line))
    {
        pos = line.find(to_find);
        if (pos != std::string::npos)
            line.replace(line.find(to_find), to_find.length(), replace);
        write_file << line << std::endl;
    }
}

int main(int ac, char **av)
{
    if (check_arg(ac,av))
        return 1;
    
    std::string file_name(av[1]);
    std::ifstream read_file(av[1]);

    if (check_ifstream(read_file, file_name))
        return 1;
    file_name = file_name + ".replace";
    std::ofstream write_file(file_name.c_str());

    if (check_ofstream(write_file, read_file, file_name))
        return 1;
    
    write_replace_file(read_file, write_file, av);
	read_file.close();
	write_file.close();
    return 0;
}