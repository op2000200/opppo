#include <gtest/gtest.h>
#include "OOP.cpp"
#include "File.h"

// Тест для функции loadTestElements
TEST(FileManagementTests, LoadTestElements) {
    loadTestElements();
    EXPECT_EQ(fileVector.size(), 15);

    // Проверяем, что некоторые элементы загружены
    EXPECT_EQ(fileVector[0].type, Picture);
    EXPECT_EQ(fileVector[5].type, Video);
    EXPECT_EQ(fileVector[14].type, Audio);
}

// Тест для функции addElem
TEST(FileManagementTests, AddElem) {
    int initial_size = fileVector.size();
    std::string invalid_input = "1\nautotest\nsomedate\n100\n100\n24\n1\n";
    std::istringstream input_stream(invalid_input);
    std::cin.rdbuf(input_stream.rdbuf());
    addElem();

    EXPECT_EQ(fileVector.size(), initial_size + 1);
}
// Тест для функции remElem
TEST(FileManagementTests, RemElem) {
    loadTestElements(); // Загружаем элементы для тестирования

    int initial_size = fileVector.size();
    std::string invalid_input = "2\n1\n";
    std::istringstream input_stream(invalid_input);
    std::cin.rdbuf(input_stream.rdbuf());
    remElem();

    EXPECT_LT(fileVector.size(), initial_size);
}

// Тест для функции обработки ввода
TEST(FileManagementTests, HandleInvalidInput) {
    int initial_size = fileVector.size();
    std::string invalid_input = "1\nautotest\nsomedate\nwrong\n-100\n100\n24\n1\n";
    std::istringstream input_stream(invalid_input);
    std::cin.rdbuf(input_stream.rdbuf());
    addElem();
    EXPECT_EQ(fileVector.size(), initial_size + 1);
}

// Тест для класса File
TEST(FileTests, SetAndGetName) {
    File file;
    file.setName("TestFile");
    EXPECT_EQ(file.getName(), "TestFile");
}

TEST(FileTests, SetAndGetLCT) {
    File file;
    file.setLCT("12.12.2022/12:00");
    EXPECT_EQ(file.getLCT(), "12.12.2022/12:00");
}

TEST(FileTests, GetData) {
    File file;
    file.setName("TestFile");
    file.setLCT("12.12.2022/12:00");
    std::vector<std::string> data = file.getData();

    EXPECT_EQ(data.size(), 2);
    EXPECT_EQ(data[0], "TestFile");
    EXPECT_EQ(data[1], "12.12.2022/12:00");
}

TEST(FileTests, GetHeader) {
    File file;
    std::vector<std::string> header = file.getHeader();

    EXPECT_EQ(header.size(), 2);
    EXPECT_EQ(header[0], "Name");
    EXPECT_EQ(header[1], "LastChangeTime");
}

// Тесты для класса VideoFile
TEST(VideoFileTests, SetAndGetResolution) {
    VideoFile videoFile;
    Resolution res;
    res.x = 1920;
    res.y = 1080;

    videoFile.setResolution(res);
    EXPECT_EQ(videoFile.getResolution().x, 1920);
    EXPECT_EQ(videoFile.getResolution().y, 1080);
}

TEST(VideoFileTests, SetAndGetFPS) {
    VideoFile videoFile;
    videoFile.setFPS(60);
    EXPECT_EQ(videoFile.getFPS(), 60);
}

TEST(VideoFileTests, GetData) {
    VideoFile videoFile;
    Resolution res;
    res.x = 1920;
    res.y = 1080;
    videoFile.setResolution(res);
    videoFile.setName("TestVideo");
    videoFile.setLCT("12.12.2022/12:00");
    videoFile.setFPS(30);

    std::vector<std::string> data = videoFile.getData();

    EXPECT_EQ(data.size(), 5);
    EXPECT_EQ(data[0], "TestVideo");
    EXPECT_EQ(data[1], "12.12.2022/12:00");
    EXPECT_EQ(data[2], "1920");
    EXPECT_EQ(data[3], "1080");
    EXPECT_EQ(data[4], "30");
}

TEST(VideoFileTests, GetHeader) {
    VideoFile videoFile;
    std::vector<std::string> header = videoFile.getHeader();

    EXPECT_EQ(header.size(), 5);
    EXPECT_EQ(header[0], "Name");
    EXPECT_EQ(header[1], "LastChangeTime");
    EXPECT_EQ(header[2], "Resolution.x");
    EXPECT_EQ(header[3], "Resolution.y");
    EXPECT_EQ(header[4], "FramesPerSecond");
}

// Тесты для класса AudioFile
TEST(AudioFileTests, SetAndGetBitrate) {
    AudioFile audioFile;
    audioFile.setBitrate(128);
    EXPECT_EQ(audioFile.getBitrate(), 128);
}

TEST(AudioFileTests, SetAndGetLength) {
    AudioFile audioFile;
    audioFile.setLength(300);
    EXPECT_EQ(audioFile.getLength(), 300);
}

TEST(AudioFileTests, GetData) {
    AudioFile audioFile;
    audioFile.setName("TestAudio");
    audioFile.setLCT("12.12.2022/12:00");
    audioFile.setBitrate(128);
    audioFile.setLength(300);

    std::vector<std::string> data = audioFile.getData();

    EXPECT_EQ(data.size(), 4);
    EXPECT_EQ(data[0], "TestAudio");
    EXPECT_EQ(data[1], "12.12.2022/12:00");
    EXPECT_EQ(data[2], "128");
    EXPECT_EQ(data[3], "300");
}

TEST(AudioFileTests, GetHeader) {
    AudioFile audioFile;
    std::vector<std::string> header = audioFile.getHeader();

    EXPECT_EQ(header.size(), 4);
    EXPECT_EQ(header[0], "Name");
    EXPECT_EQ(header[1], "LastChangeTime");
    EXPECT_EQ(header[2], "Bitrate");
    EXPECT_EQ(header[3], "Length");
}

// Тесты для класса Image
TEST(ImageTests, SetAndGetResolution) {
    Image image;
    Resolution res;
    res.x = 800;

    res.y = 600;

    image.setResolution(res);
    EXPECT_EQ(image.getResolution().x, 800);
    EXPECT_EQ(image.getResolution().y, 600);
}

TEST(ImageTests, SetAndGetImageType) {
    Image image;
    image.setImageType(JPG);
    EXPECT_EQ(image.getImageType(), JPG);
}

TEST(ImageTests, GetData) {
    Image image;
    Resolution res;
    res.x = 800;
    res.y = 600;
    image.setResolution(res);
    image.setName("TestImage");
    image.setLCT("12.12.2022/12:00");
    image.setImageType(PNG);

    std::vector<std::string> data = image.getData();

    EXPECT_EQ(data.size(), 5);
    EXPECT_EQ(data[0], "TestImage");
    EXPECT_EQ(data[1], "12.12.2022/12:00");
    EXPECT_EQ(data[2], "800");
    EXPECT_EQ(data[3], "600");
    EXPECT_EQ(data[4], "PNG");
}

TEST(ImageTests, GetHeader) {
    Image image;
    std::vector<std::string> header = image.getHeader();

    EXPECT_EQ(header.size(), 5);
    EXPECT_EQ(header[0], "Name");
    EXPECT_EQ(header[1], "LastChangeTime");
    EXPECT_EQ(header[2], "Resolution.x");
    EXPECT_EQ(header[3], "Resolution.y");
    EXPECT_EQ(header[4], "Type");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}