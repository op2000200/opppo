package main

import (
	"fmt"
)

var vault [1024]file
var firstAvailable int = 0

type file struct {
	category string
	name     string
	date     string
	res      string
	fps      string
	bitrate  string
	length   string
	format   string
}

func print(line file) {
	switch line.category {
	case "video":
		{
			fmt.Println(line.category, line.name, line.date, line.res, line.fps)
		}
	case "audio":
		{
			fmt.Println(line.category, line.name, line.date, line.bitrate, line.length)
		}
	case "image":
		{
			fmt.Println(line.category, line.name, line.date, line.res, line.format)
		}
	}
}

func setNuls(par string, line string) {
	for i := 0; i < firstAvailable; i++ {
		switch par {
		case "category":
			{
				if vault[i].category == line {
					vault[i].category = ""
				}
			}
		case "name":
			{
				if vault[i].name == line {
					vault[i].category = ""
				}
			}
		case "date":
			{
				if vault[i].date == line {
					vault[i].category = ""
				}
			}
		case "resolution":
			{
				if vault[i].res == line {
					vault[i].category = ""
				}
			}
		case "fps":
			{
				if vault[i].fps == line {
					vault[i].category = ""
				}
			}
		case "bitrate":
			{
				if vault[i].bitrate == line {
					vault[i].category = ""
				}
			}
		case "length":
			{
				if vault[i].length == line {
					vault[i].category = ""
				}
			}
		case "format":
			{
				if vault[i].format == line {
					vault[i].category = ""
				}
			}
		default:
			{
				fmt.Println("Unknown parameter")
			}
		}
	}
}

func delNuls() {
	for i := 0; i < firstAvailable; i++ {
		if vault[i].category == "" {
			for j := i; j < firstAvailable-1; j++ {
				vault[j] = vault[j+1]
			}
			firstAvailable--
		}
	}
}

func initialDB() {
	var buf [4]string
	buf = [4]string{"vid1", "10.10.2000", "fullhd", "24"}
	add(buf[0:], &vault, firstAvailable, createVideo)
	buf = [4]string{"vid2", "10.10.2001", "hd", "60"}
	add(buf[0:], &vault, firstAvailable, createVideo)
	buf = [4]string{"vid3", "10.10.2002", "quadhd", "144"}
	add(buf[0:], &vault, firstAvailable, createVideo)
	buf = [4]string{"vid3", "10.10.2003", "hd", "24"}
	add(buf[0:], &vault, firstAvailable, createVideo)

	buf = [4]string{"aud1", "10.11.2000", "10", "30"}
	add(buf[0:], &vault, firstAvailable, createAudio)
	buf = [4]string{"aud1", "10.11.2001", "20", "60"}
	add(buf[0:], &vault, firstAvailable, createAudio)
	buf = [4]string{"aud2", "10.11.2002", "20", "90"}
	add(buf[0:], &vault, firstAvailable, createAudio)
	buf = [4]string{"aud2", "10.11.2003", "30", "120"}
	add(buf[0:], &vault, firstAvailable, createAudio)

	buf = [4]string{"img1", "10.12.2000", "quadhd", "png"}
	add(buf[0:], &vault, firstAvailable, createImage)
	buf = [4]string{"img2", "10.12.2000", "quadhd", "jpg"}
	add(buf[0:], &vault, firstAvailable, createImage)
	buf = [4]string{"img3", "10.12.2000", "quadhd", "bmp"}
	add(buf[0:], &vault, firstAvailable, createImage)
	buf = [4]string{"img4", "10.12.2000", "quadhd", "jpeg"}
	add(buf[0:], &vault, firstAvailable, createImage)
}

func createVideo(name string, date string, res string, fps string) file {
	var result file
	result.category = "video"
	result.name = name
	result.date = date
	result.res = res
	result.fps = fps
	firstAvailable++
	return result
}

func createAudio(name string, date string, bitrate string, length string) file {
	var result file
	result.category = "audio"
	result.name = name
	result.date = date
	result.bitrate = bitrate
	result.length = length
	firstAvailable++
	return result
}

func createImage(name string, date string, res string, format string) file {
	var result file
	result.category = "image"
	result.name = name
	result.date = date
	result.res = res
	result.format = format
	firstAvailable++
	return result
}

func add(line []string, vault *[1024]file, id int, create func(name string, date string, par1 string, par2 string) file) {
	vault[id] = create(line[0], line[1], line[2], line[3])
}

func adding() {
	fmt.Println("Type file parametrs according to example:")
	fmt.Println("video exampleName 01.01.0001 fullhd 24")
	fmt.Println("audio exampleName 01.01.0001 120 13")
	fmt.Println("image exampleName 01.01.0001 hd png")
	var input [5]string
	fmt.Scanln(&input[0], &input[1], &input[2], &input[3], &input[4])
	switch input[0] {
	case "video":
		{
			add(input[1:], &vault, firstAvailable, createVideo)
		}
	case "audio":
		{
			add(input[1:], &vault, firstAvailable, createAudio)
		}
	case "image":
		{
			add(input[1:], &vault, firstAvailable, createImage)
		}
	default:
		{
			fmt.Println("Unknown file format in first parameter")
		}
	}
	return
}

func removing() {
	fmt.Println("Type parameter and value, all files with matching value will be deleted:")
	fmt.Println("Available parameters: category, name, date, resolution, fps, bitrate, length, format")
	var input [2]string
	fmt.Scanln(&input[0], &input[1])
	setNuls(input[0], input[1])
	delNuls()
	return
}

func printing() {
	for i := 0; i < firstAvailable; i++ {
		print(vault[i])
	}
	return
}

func main() {
	initialDB()
	var input string
	for i := 0; i < 1; {
		fmt.Println("Available commands: add, remove, print, exit")
		fmt.Scanln(&input)
		switch input {
		case "exit":
			{
				i++
			}
		case "add":
			{
				adding()
			}
		case "remove":
			{
				removing()
			}
		case "print":
			{
				printing()
			}
		default:
			{
				fmt.Println("Unknown command")
			}
		}
	}
}
