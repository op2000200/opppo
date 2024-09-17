#include <iostream>
#include <string>
#include <vector>
#include <tabulate/tabulate.hpp>
#include <tabulate/table.hpp>

#include "File.h"

enum Type
{
	Video,
	Audio,
	Picture
};

struct Container
{
	Type type;
	VideoFile videoFile;
	AudioFile audioFile;
	Image image;
};

void loadTestElements();

void firstMessage();

void addElem();

void remElem();
void remByName();
void remVideo();
void remAudio();
void remImage();

void showMenu();
void showAllUngroupped();
void showAllGroupped();

std::vector<Container> fileVector;

int main()
{
	std::string input;
	int functionNum;
	loadTestElements();
	std::cout << "Welcome.\n";
	while (true)
	{
		firstMessage();
		while (true)
		{
			bool correct = true;
			std::cin >> input;
			try
			{
				functionNum = std::stoi(input);
			}
			catch (const std::exception&)
			{
				//not a int
				correct = false;
				std::cout << input << " is not a number.\n";
			}
			if (correct)
			{
				break;
			}
		}
		std::system("cls");
		switch (functionNum)
		{
			case 1:
			{
				showMenu();
				break;
			}
			case 2:
			{
				addElem();
				break;
			}
			case 3:
			{
				remElem();
				break;
			}
			case 4:
			{
				std::cout << "Bye." << std::endl;
				return 0;
				break;
			}
			default:
			{
				std::cout << "There is no function under number " << input << std::endl << std::endl;
				break;
			}
		}
	}
	return 0;
}

void loadTestElements()
{
	Container example;
	example.type = Picture;
	fileVector.push_back(example);

	example.type = Video;
	fileVector.push_back(example);

	example.type = Audio;
	fileVector.push_back(example);

	example.type = Picture;
	fileVector.push_back(example);

	example.type = Audio;
	fileVector.push_back(example);

	example.type = Video;
	example.videoFile.setName("One");
	example.videoFile.setLCT("14.09.2024/9:05");
	Resolution res;
	res.x = 100;
	res.y = 100;
	example.videoFile.setResolution(res);
	example.videoFile.setFPS(24);
	fileVector.push_back(example);

	example.type = Video;
	example.videoFile.setName("Two");
	example.videoFile.setLCT("14.09.2014/9:05");
	res.x = 1000;
	res.y = 1000;
	example.videoFile.setResolution(res);
	example.videoFile.setFPS(240);
	fileVector.push_back(example);

	example.type = Video;
	example.videoFile.setName("One");
	example.videoFile.setLCT("14.09.2024/9:05");
	res.x = 100;
	res.y = 100;
	example.videoFile.setResolution(res);
	example.videoFile.setFPS(24);
	fileVector.push_back(example);

	example.type = Video;
	example.videoFile.setName("Test1");
	example.videoFile.setLCT("13.07.2024/18:07");
	res.x = 341256;
	res.y = 543;
	example.videoFile.setResolution(res);
	example.videoFile.setFPS(5647);
	fileVector.push_back(example);

	example.type = Picture;
	example.image.setName("Test1");
	example.image.setLCT("13.07.2024/18:07");
	res.x = 341256;
	res.y = 543;
	example.image.setResolution(res);
	example.image.setImageType(PNG);
	fileVector.push_back(example);

	example.type = Picture;
	example.image.setName("Test4");
	example.image.setLCT("4.11.7549/18:07");
	res.x = 75483;
	res.y = 43;
	example.image.setResolution(res);
	example.image.setImageType(JPG);
	fileVector.push_back(example);

	example.type = Picture;
	example.image.setName("Test4");
	example.image.setLCT("4.11.7549/18:07");
	res.x = 75483;
	res.y = 43;
	example.image.setResolution(res);
	example.image.setImageType(BMP);
	fileVector.push_back(example);

	example.type = Picture;
	example.image.setName("Test4");
	example.image.setLCT("4.11.7549/18:07");
	res.x = 75483;
	res.y = 43;
	example.image.setResolution(res);
	example.image.setImageType(Other);
	fileVector.push_back(example);

	example.type = Audio;
	example.audioFile.setName("Test1");
	example.audioFile.setLCT("13.07.2024/18:07");
	example.audioFile.setBitrate(160);
	example.audioFile.setLength(10);
	fileVector.push_back(example);

	example.type = Audio;
	example.audioFile.setName("Test2");
	example.audioFile.setLCT("13.07.2024/18:07");
	example.audioFile.setBitrate(1640);
	example.audioFile.setLength(104);
	fileVector.push_back(example);
}

void firstMessage()
{
	std::cout << "What you want to do? Type a number and press enter.\nType 1 to show what inside of container;\nType 2 to add element to container;\nType 3 to remove element from container;\nType 4 to close programm.\n";
}

void addElem()
{
	while (true)
	{
		bool correct2 = true;
		std::cout << "To add video file type 1 and press enter, to add audio file type 2 and press enter, to add image type 3 and press enter.\n";
		std::string input;
		int functionNum;
		Container file;
		while (true)
		{
			bool correct = true;
			std::cin >> input;
			try
			{
				functionNum = std::stoi(input);
			}
			catch (const std::exception&)
			{
				//not a int
				correct = false;
				std::cout << input << " is not a number.\n";
			}
			if (correct)
			{
				break;
			}
		}
		system("cls");
		switch (functionNum)
		{
		case 1:
		{
			file.type = Video;
			std::cout << "\nEnter name of file:\n";
			input.clear();
			std::cin >> input;
			file.videoFile.setName(input);
			std::cout << "\nEnter last change time, following the example.\nPattern: dd.mm.yyyy/HH.MM\nExample: 13.09.2024/19:48\n";
			input.clear();
			std::cin >> input;
			file.videoFile.setLCT(input);
			Resolution res;
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter width:\n";
				input.clear();
				std::cin >> input;
				try
				{
					res.x = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					break;
				}
			}
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter height:\n";
				input.clear();
				std::cin >> input;
				try
				{
					res.y = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					break;
				}
			}
			file.videoFile.setResolution(res);
			int fps;
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter frames per second:\n";
				input.clear();
				std::cin >> input;
				try
				{
					fps = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					break;
				}
			}
			file.videoFile.setFPS(fps);
			fileVector.push_back(file);
			break;
		}
		case 2:
		{
			file.type = Audio;
			std::cout << "\nEnter name of file:\n";
			input.clear();
			std::cin >> input;
			file.audioFile.setName(input);
			std::cout << "\nEnter last change time, following the example.\nPattern: dd.mm.yyyy/HH.MM\nExample: 13.09.2024/19:48\n";
			input.clear();
			std::cin >> input;
			file.audioFile.setLCT(input);
			int num;
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter bitrate:\n";
				input.clear();
				std::cin >> input;
				try
				{
					num = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					break;
				}
			}
			file.audioFile.setBitrate(num);
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter length in seconds:\n";
				input.clear();
				std::cin >> input;
				try
				{
					num = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					break;
				}
			}
			file.audioFile.setLength(num);
			fileVector.push_back(file);
			break;
		}
		case 3:
		{
			file.type = Picture;
			std::cout << "\nEnter name of file:\n";
			input.clear();
			std::cin >> input;
			file.image.setName(input);
			std::cout << "\nEnter last change time, following the example.\nPattern: dd.mm.yyyy/HH.MM\nExample: 13.09.2024/19:48\n";
			input.clear();
			std::cin >> input;
			file.image.setLCT(input);
			Resolution res;
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter width:\n";
				input.clear();
				std::cin >> input;
				try
				{
					res.x = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					break;
				}
			}
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter height:\n";
				input.clear();
				std::cin >> input;
				try
				{
					res.y = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					break;
				}
			}
			file.image.setResolution(res);
			int num;
			while (true)
			{
				bool correct = true;
				std::cout << "\nEnter 1 if image type is JPG, 2 if PNG, 3 if BMP or 4 if none of that:\n";
				input.clear();
				std::cin >> input;
				try
				{
					num = std::stoi(input);
				}
				catch (const std::exception&)
				{
					//not a int
					correct = false;
					std::cout << input << " is not a number.\n";
				}
				if (correct)
				{
					switch (num)
					{
					case 1:
					{
						file.image.setImageType(JPG);
						break;
					}
					case 2:
					{
						file.image.setImageType(PNG);
						break;
					}
					case 3:
					{
						file.image.setImageType(BMP);
						break;
					}
					case 4:
					{
						file.image.setImageType(Other);
						break;
					}
					default:
					{
						correct = false;
						std::cout << "There is no image type under number " << input << std::endl << std::endl;
						break;
					}
					}
					if (correct)
					{
						break;
					}
				}
			}
			fileVector.push_back(file);
			break;
		}
		default:
		{
			std::cout << "There is no function under number " << input << std::endl << std::endl;
			correct2 = false;
			break;
		}
		}
		if (correct2)
		{
			break;
		}
	}
	std::cout << "\nDone.\nPress any letter and enter to return to main menu.";
	std::string iDontHowTODoThisWithoutAnotherStringVar;
	std::cin >> iDontHowTODoThisWithoutAnotherStringVar;
	system("cls");
	return;
}

void remElem()
{
	while (true)
	{
		bool correct2 = true;
		std::cout << "To delete files with certain name type 1 \nTo delete all video files type 2 \nTo delete all audio files type 3 \nTo delete all image files type 4 \n";
		std::string input;
		int functionNum;
		while (true)
		{
			bool correct = true;
			std::cin >> input;
			try
			{
				functionNum = std::stoi(input);
			}
			catch (const std::exception&)
			{
				//not a int
				correct = false;
				std::cout << input << " is not a number.\n";
			}
			if (correct)
			{
				break;
			}
		}
		system("cls");
		switch (functionNum)
		{
		case 1:
		{
			remByName();
			break;
		}
		case 2:
		{
			remVideo();
			break;
		}
		case 3:
		{
			remAudio();
			break;
		}
		case 4:
		{
			remImage();
			break;
		}
		default:
		{
			std::cout << "There is no function under number " << input << std::endl << std::endl;
			correct2 = false;
			break;
		}
		}
		if (correct2)
		{
			break;
		}
	}
}

void remByName()
{
	system("cls");
	std::cout << "Type file name that you want to be deleted:\n";
	std::string input;
	std::cin >> input;
	int counterOfDeletedFiles = 0;
	int i = 0;
	while (i < fileVector.size())
	{
		switch (fileVector[i].type)
		{
		case Video:
		{
			if (fileVector[i].videoFile.getName() == input)
			{
				fileVector.erase(fileVector.begin() + i);
				counterOfDeletedFiles++;
			}
			else
			{
				i++;
			}
			break;
		}
		case Audio:
		{
			if (fileVector[i].audioFile.getName() == input)
			{
				fileVector.erase(fileVector.begin() + i);
				counterOfDeletedFiles++;
			}
			else
			{
				i++;
			}
			break;
		}
		case Picture:
		{
			if (fileVector[i].image.getName() == input)
			{
				fileVector.erase(fileVector.begin() + i);
				counterOfDeletedFiles++;
			}
			else
			{
				i++;
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	std::cout << "\nDone. " << counterOfDeletedFiles << " has been deleted. Press any letter and enter to return to main menu.";
	std::string iDontHowTODoThisWithoutAnotherStringVar;
	std::cin >> iDontHowTODoThisWithoutAnotherStringVar;
	system("cls");
	return;
}

void remVideo()
{
	system("cls");
	int counterOfDeletedFiles = 0;
	int i = 0;
	while (i < fileVector.size())
	{
		switch (fileVector[i].type)
		{
		case Video:
		{
			fileVector.erase(fileVector.begin() + i);
			counterOfDeletedFiles++;
			break;
		}
		default:
		{
			i++;
			break;
		}
		}
	}
	std::cout << "\nDone. " << counterOfDeletedFiles << " has been deleted. Press any letter and enter to return to main menu.";
	std::string iDontHowTODoThisWithoutAnotherStringVar;
	std::cin >> iDontHowTODoThisWithoutAnotherStringVar;
	system("cls");
	return;
}

void remAudio()
{
	system("cls");
	int counterOfDeletedFiles = 0;
	int i = 0;
	while (i < fileVector.size())
	{
		switch (fileVector[i].type)
		{
		case Audio:
		{
			fileVector.erase(fileVector.begin() + i);
			counterOfDeletedFiles++;
			break;
		}
		default:
		{
			i++;
			break;
		}
		}
	}
	std::cout << "\nDone. " << counterOfDeletedFiles << " has been deleted. Press any letter and enter to return to main menu.";
	std::string iDontHowTODoThisWithoutAnotherStringVar;
	std::cin >> iDontHowTODoThisWithoutAnotherStringVar;
	system("cls");
	return;
}

void remImage()
{
	system("cls");
	int counterOfDeletedFiles = 0;
	int i = 0;
	while (i < fileVector.size())
	{
		switch (fileVector[i].type)
		{
		case Picture:
		{
			fileVector.erase(fileVector.begin() + i);
			counterOfDeletedFiles++;
			break;
		}
		default:
		{
			i++;
			break;
		}
		}
	}
	std::cout << "\nDone. " << counterOfDeletedFiles << " has been deleted. Press any letter and enter to return to main menu.";
	std::string iDontHowTODoThisWithoutAnotherStringVar;
	std::cin >> iDontHowTODoThisWithoutAnotherStringVar;
	system("cls");
	return;
}

void showMenu()
{
	while (true)
	{
		bool correct2 = true;
		std::cout << "If you want to group your list by types, type 1 and press enter, else type 2 and press enter.\n";
		std::string input;
		int functionNum;
		while (true)
		{
			bool correct = true;
			std::cin >> input;
			try
			{
				functionNum = std::stoi(input);
			}
			catch (const std::exception&)
			{
				//not a int
				correct = false;
				std::cout << input << " is not a number.\n";
			}
			if (correct)
			{
				break;
			}
		}
		system("cls");
		switch (functionNum)
		{
		case 1:
		{
			showAllGroupped();
			break;
		}
		case 2:
		{
			showAllUngroupped();
			break;
		}
		default:
		{
			std::cout << "There is no function under number " << input << std::endl << std::endl;
			correct2 = false;
			break;
		}
		}
		if (correct2)
		{
			break;
		}
	}
	system("cls");
	return;
}

void showAllUngroupped()
{
	tabulate::Table table;
	std::vector<std::string> lineBuffer;
	for (int i = 0; i < fileVector.size(); i++)
	{
		switch (fileVector[i].type)
		{
			case Video:
			{
				lineBuffer = fileVector[i].videoFile.getData();
				tabulate::RowStream streamBuffer;
				streamBuffer << "Video";
				for (int i = 0; i < lineBuffer.size(); i++)
				{
					streamBuffer << lineBuffer[i];
				}
				table.add_row(streamBuffer);
				lineBuffer.clear();
				break;
			}
			case Audio:
			{
				lineBuffer = fileVector[i].audioFile.getData();
				tabulate::RowStream streamBuffer;
				streamBuffer << "Audio";
				for (int i = 0; i < lineBuffer.size(); i++)
				{
					streamBuffer << lineBuffer[i];
				}
				table.add_row(streamBuffer);
				lineBuffer.clear();
				break;
			}
			case Picture:
			{
				lineBuffer = fileVector[i].image.getData();
				tabulate::RowStream streamBuffer;
				streamBuffer << "Picture";
				for (int i = 0; i < lineBuffer.size(); i++)
				{
					streamBuffer << lineBuffer[i];
				}
				table.add_row(streamBuffer);
				lineBuffer.clear();
				break;
			}
			default:
			{
				break;
			}
		}
	}
	std::cout << table << "\n\nPress any letter and enter to return to main menu.";
	std::string iDontHowTODoThisWithoutAnotherStringVar;
	std::cin >> iDontHowTODoThisWithoutAnotherStringVar;
	return;
}

void showAllGroupped()
{
	tabulate::Table* table = new tabulate::Table;
	std::vector<std::string> lineBuffer;

	tabulate::RowStream headerVideo;
	lineBuffer = fileVector[0].videoFile.getHeader();
	for (int i = 0; i < lineBuffer.size(); i++)
	{
		headerVideo << lineBuffer[i];
	}
	table->add_row(headerVideo);
	lineBuffer.clear();
	for (int i = 0; i < fileVector.size(); i++)
	{
		if (fileVector[i].type == Video)
		{
			lineBuffer = fileVector[i].videoFile.getData();
			tabulate::RowStream streamBuffer;
			for (int i = 0; i < lineBuffer.size(); i++)
			{
				streamBuffer << lineBuffer[i];
			}
			table->add_row(streamBuffer);
			lineBuffer.clear();
		}
	}
	std::cout << "Video:\n" << table[0] << "\n\n";

	table = new tabulate::Table;
	tabulate::RowStream headerAudio;
	lineBuffer = fileVector[0].audioFile.getHeader();
	for (int i = 0; i < lineBuffer.size(); i++)
	{
		headerAudio << lineBuffer[i];
	}
	table->add_row(headerAudio);
	lineBuffer.clear();
	for (int i = 0; i < fileVector.size(); i++)
	{
		if (fileVector[i].type == Audio)
		{
			lineBuffer = fileVector[i].audioFile.getData();
			tabulate::RowStream streamBuffer;
			for (int i = 0; i < lineBuffer.size(); i++)
			{
				streamBuffer << lineBuffer[i];
			}
			table->add_row(streamBuffer);
			lineBuffer.clear();
		}
	}
	std::cout << "Audio:\n" << table[0] << "\n\n";

	table = new tabulate::Table;
	tabulate::RowStream headerImage;
	lineBuffer = fileVector[0].image.getHeader();
	for (int i = 0; i < lineBuffer.size(); i++)
	{
		headerImage << lineBuffer[i];
	}
	table->add_row(headerImage);
	lineBuffer.clear();
	for (int i = 0; i < fileVector.size(); i++)
	{
		if (fileVector[i].type == Picture)
		{
			lineBuffer = fileVector[i].image.getData();
			tabulate::RowStream streamBuffer;
			for (int i = 0; i < lineBuffer.size(); i++)
			{
				streamBuffer << lineBuffer[i];
			}
			table->add_row(streamBuffer);
			lineBuffer.clear();
		}
	}
	std::cout << "Picture:\n" << table[0] << "\n\nPress any letter and enter to return to main menu.";

	std::string iDontHowTODoThisWithoutAnotherStringVar;
	std::cin >> iDontHowTODoThisWithoutAnotherStringVar;
	return;
}
