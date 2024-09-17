#include "File.h"

File::File()
{
	name = "placeHolder";
	lastChangeTime = "00.00.0000/00:00";
}

File::~File()
{
}

void File::setName(std::string in)
{
	name = in;
}

std::string File::getName()
{
	return name;
}

void File::setLCT(std::string in)
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
	result.push_back(name);
	result.push_back(lastChangeTime);
	return result;
}

std::vector<std::string> File::getHeader()
{
	std::vector<std::string> result;
	result.push_back("Name");
	result.push_back("LastChangeTime");
	return result;
}

VideoFile::VideoFile()
{
	resolution.x = 0;
	resolution.y = 0;
	framesPerSecond = 0;
}

VideoFile::~VideoFile()
{
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
	result.push_back(name);
	result.push_back(lastChangeTime);
	result.push_back(std::to_string(resolution.x));
	result.push_back(std::to_string(resolution.y));
	result.push_back(std::to_string(framesPerSecond));
	return result;
}

std::vector<std::string> VideoFile::getHeader()
{
	std::vector<std::string> result;
	result.push_back("Name");
	result.push_back("LastChangeTime");
	result.push_back("Resolution.x");
	result.push_back("Resolution.y");
	result.push_back("FramesPerSecond");
	return result;
}

AudioFile::AudioFile()
{
	bitrate = 0;
	length = 0;
}

AudioFile::~AudioFile()
{
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
	result.push_back(name);
	result.push_back(lastChangeTime);
	result.push_back(std::to_string(bitrate));
	result.push_back(std::to_string(length));
	return result;
}

std::vector<std::string> AudioFile::getHeader()
{
	std::vector<std::string> result;
	result.push_back("Name");
	result.push_back("LastChangeTime");
	result.push_back("Bitrate");
	result.push_back("Length");
	return result;
}

Image::Image()
{
	resolution.x = 0;
	resolution.y = 0;
	type = Other;
}

Image::~Image()
{
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
	result.push_back(name);
	result.push_back(lastChangeTime);
	result.push_back(std::to_string(resolution.x));
	result.push_back(std::to_string(resolution.y));
	switch (type)
	{
	case JPG:
	{
		result.push_back("JPG");
		break;
	}
	case PNG:
	{
		result.push_back("PNG");
		break;
	}
	case BMP:
	{
		result.push_back("BMP");
		break;
	}
	case Other:
	{
		result.push_back("Other");
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
	result.push_back("Name");
	result.push_back("LastChangeTime");
	result.push_back("Resolution.x");
	result.push_back("Resolution.y");
	result.push_back("Type");
	return result;
}
