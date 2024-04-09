/**
 * @file translator.h
 * @brief Заголовочный файл, содержащий определения структур и классов.
 */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
#include <libs/json.hpp>

using json = nlohmann::json;

/**
 * @brief Класс Translator для перевода текста с помощью Yandex.Translate API.
 */
class Translator {
public:
    /**
     * @brief Конструктор класса Translator.
     * 
     * @param iam_token IAM-токен для аутентификации в Yandex.Translate API.
     * @param folder_id Идентификатор папки в Yandex.Cloud.
     */
    Translator(const std::string& iam_token, const std::string& folder_id);
    
    /**
     * @brief Деструктор класса Translator.
     */
    ~Translator();

    /**
     * @brief Функция для перевода текста.
     * 
     * @param target_language Язык, на который нужно перевести текст.
     * @param texts Вектор строк с текстом для перевода.
     * @return Строка с переведенным текстом.
     */
    std::string translate(const std::string& target_language, const std::vector<std::string>& texts);

private:
    const std::string IAM_TOKEN; /**< IAM-токен для аутентификации в Yandex.Translate API. */
    const std::string folder_id; /**< Идентификатор папки в Yandex.Cloud. */

    /**
     * @brief Функция обратного вызова для обработки данных, полученных от сервера.
     * 
     * @param contents Указатель на данные, полученные от сервера.
     * @param size Размер одного элемента данных.
     * @param nmemb Количество элементов данных.
     * @param output Строка, в которую записываются полученные данные.
     * @return Реальный размер полученных данных.
     */
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output);

    /**
     * @brief Функция для создания тела запроса к Yandex.Translate API.
     * 
     * @param target_language Язык, на который нужно перевести текст.
     * @param texts Вектор строк с текстом для перевода.
     * @return Строка с телом запроса.
     */
    std::string buildRequestBody(const std::string& target_language, const std::vector<std::string>& texts);
};

#endif // TRANSLATOR_H
