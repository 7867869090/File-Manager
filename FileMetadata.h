#ifndef FILE_METADATA_H
#define FILE_METADATA_H

#include <iostream>
#include <string>
#include <ctime>

class FileMetaData {
private:
    std::string fileName;
    int fileSize;
    std::time_t fileCreationDate;
    std::string content;

public:
    FileMetaData() : fileName(""), fileSize(0), fileCreationDate(0), content("") {}
    FileMetaData(const std::string& name, int size, std::time_t creationDate, const std::string& fileContent = "")
        : fileName(name), fileSize(size), fileCreationDate(creationDate), content(fileContent) {}

    std::string getFileName() const {
        return fileName;
    }

    void setFileName(const std::string& name) {
        fileName = name;
    }

    int getFileSize() const {
        return fileSize;
    }

    void setFileSize(int size) {
        fileSize = size;
    }

    std::time_t getFileCreationDate() const {
        return fileCreationDate;
    }

    void setFileCreationDate(std::time_t creationDate) {
        fileCreationDate = creationDate;
    }

    std::string getContent() const {
        return content;
    }

    void setContent(const std::string& newContent) {
        content = newContent;
    }
    void appendContentWithSpace(const std::string& additionalContent) {
        content += " " + additionalContent;
    }


    void removeContentBetweenWords(const std::string& startWord, const std::string& endWord) {
        size_t startPos = content.find(startWord);
                size_t endPos = content.find(endWord, startPos + startWord.length());

                if (startPos != std::string::npos && endPos != std::string::npos) {
                    content.erase(startPos, endPos - startPos + endWord.length());
                    std::cout << "Content removed between '" << startWord << "' and '" << endWord  << "'.\n"<<std::endl;
                }
                else {
                    std::cout << "Words not found. No content removed.\n";
                }
    }




    void displayDataInformation() const {
        std::cout << "\nFile Name: " << fileName << std::endl;
        std::cout << "File Size: " << fileSize << " bytes" << std::endl;
        std::cout << "File Content: " << content << std::endl;


        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&fileCreationDate));

        std::cout << "File Creation Date: " << buffer <<"\n"<< std::endl;
    }
};

#endif
