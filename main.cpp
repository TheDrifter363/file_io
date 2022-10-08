#include <iostream>
#include <filesystem>
#include <string>

int main()
{
//	std::cout << "Hello World" << std::endl;
	using namespace std;
	namespace fs = std::filesystem;

	cout << "Please specify the input folder." << endl;
	string folder_in = "";
	cin >> folder_in;
	fs::path path_in = folder_in;
	cout << path_in << endl;

	cout << "Please specify the output folder." << endl;
	string folder_out = "";
	cin >> folder_out;
	fs::path path_out = folder_out;
	cout << path_out << endl;

	try
	{
		cout << "Copying files from " << folder_in << " to " << folder_out << "." << endl;
		fs::copy(path_in, path_out, fs::copy_options::overwrite_existing | fs::copy_options::recursive);
	}
	catch(fs::filesystem_error &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
