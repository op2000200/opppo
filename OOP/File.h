#pragma once
#include <iostream>
#include <tabulate/tabulate.hpp>
#include <vector>
#include <string>

struct Resolution
{
	int x;
	int y;
};

enum ImageType
{
	JPG,
	PNG,
	BMP,
	Other
};

class File
{
public:
	File();
	~File();

	void setName(std::string in);
	std::string getName();
	void setLCT(std::string in);
	std::string getLCT();
	virtual std::vector<std::string> getData();
	virtual std::vector<std::string> getHeader();

protected:
	std::string name;
	std::string lastChangeTime;
};

class VideoFile : public File
{
public:
	VideoFile();
	~VideoFile();

	void setResolution(Resolution input);
	Resolution getResolution();
	void setFPS(int input);
	int getFPS();
	virtual std::vector<std::string> getData();
	virtual std::vector<std::string> getHeader();
private:
	Resolution resolution;
	int framesPerSecond;
};

class AudioFile : public File
{
public:
	AudioFile();
	~AudioFile();

	void setBitrate(int input);
	int getBitrate();
	void setLength(int input);
	int getLength();
	virtual std::vector<std::string> getData();
	virtual std::vector<std::string> getHeader();

private:
	int bitrate;
	int length;
};

class Image : public File
{
public:
	Image();
	~Image();

	void setResolution(Resolution input);
	Resolution getResolution();
	void setImageType(ImageType input);
	ImageType getImageType();
	virtual std::vector<std::string> getData();
	virtual std::vector<std::string> getHeader();

private:
	Resolution resolution;
	ImageType type;
};
