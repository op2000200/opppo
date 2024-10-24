// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "File.h"

File::File()
{
	name = "placeHolder";
	lastChangeTime = "00.00.0000/00:00";
}

void File::setName(const std::string &in)
{
	name = in;
}

std::string File::getName()
{
	return name;
}

void File::setLCT(const std::string &in)
{
	lastChangeTime = in;
}

std::string File::getLCT()
{
	return lastChangeTime;
}

std::vector<std::string> File::getData()
{
	std::vector<std::string> result;
	result.reserve(2);
	result.emplace_back(name);
	result.emplace_back(lastChangeTime);
	return result;
}

std::vector<std::string> File::getHeader()
{
	std::vector<std::string> result;
	result.reserve(2);
	result.emplace_back("Name");
	result.emplace_back("LastChangeTime");
	return result;
}

VideoFile::VideoFile()
{
	resolution.x = 0;
	resolution.y = 0;
	framesPerSecond = 0;
}

void VideoFile::setResolution(Resolution input)
{
	resolution = input;
}

Resolution VideoFile::getResolution()
{
	return resolution;
}

void VideoFile::setFPS(int input)
{
	framesPerSecond = input;
}

int VideoFile::getFPS()
{
	return framesPerSecond;
}

std::vector<std::string> VideoFile::getData()
{
	std::vector<std::string> result;
	result.reserve(5);
	result.emplace_back(name);
	result.emplace_back(lastChangeTime);
	result.emplace_back(std::to_string(resolution.x));
	result.emplace_back(std::to_string(resolution.y));
	result.emplace_back(std::to_string(framesPerSecond));
	return result;
}

std::vector<std::string> VideoFile::getHeader()
{
	std::vector<std::string> result;
	result.reserve(5);
	result.emplace_back("Name");
	result.emplace_back("LastChangeTime");
	result.emplace_back("Resolution.x");
	result.emplace_back("Resolution.y");
	result.emplace_back("FramesPerSecond");
	return result;
}

AudioFile::AudioFile()
{
	bitrate = 0;
	length = 0;
}

void AudioFile::setBitrate(int input)
{
	bitrate = input;
}

int AudioFile::getBitrate()
{
	return bitrate;
}

void AudioFile::setLength(int input)
{
	length = input;
}

int AudioFile::getLength()
{
	return length;
}

std::vector<std::string> AudioFile::getData()
{
	std::vector<std::string> result;
	result.reserve(4);
	result.emplace_back(name);
	result.emplace_back(lastChangeTime);
	result.emplace_back(std::to_string(bitrate));
	result.emplace_back(std::to_string(length));
	return result;
}

std::vector<std::string> AudioFile::getHeader()
{
	std::vector<std::string> result;
	result.reserve(4);
	result.emplace_back("Name");
	result.emplace_back("LastChangeTime");
	result.emplace_back("Bitrate");
	result.emplace_back("Length");
	return result;
}

Image::Image()
{
	resolution.x = 0;
	resolution.y = 0;
	type = Other;
}

void Image::setResolution(Resolution input)
{
	resolution = input;
}

Resolution Image::getResolution()
{
	return resolution;
}

void Image::setImageType(ImageType input)
{
	type = input;
}

ImageType Image::getImageType()
{
	return type;
}

std::vector<std::string> Image::getData()
{
	std::vector<std::string> result;
	result.reserve(5);
	result.emplace_back(name);
	result.emplace_back(lastChangeTime);
	result.emplace_back(std::to_string(resolution.x));
	result.emplace_back(std::to_string(resolution.y));
	switch (type)
	{
	case JPG:
	{
		result.emplace_back("JPG");
		break;
	}
	case PNG:
	{
		result.emplace_back("PNG");
		break;
	}
	case BMP:
	{
		result.emplace_back("BMP");
		break;
	}
	case Other:
	{
		result.emplace_back("Other");
		break;
	}
	default:
		break;
	}
	return result;
}

std::vector<std::string> Image::getHeader()
{
	std::vector<std::string> result;
	result.reserve(5);
	result.emplace_back("Name");
	result.emplace_back("LastChangeTime");
	result.emplace_back("Resolution.x");
	result.emplace_back("Resolution.y");
	result.emplace_back("Type");
	return result;
}
