#include "translator.hpp"

Translator::Translator(const std::string &iam_token,
                       const std::string &folder_id_param)
    : IAM_TOKEN(iam_token), folder_id(folder_id_param) {
  curl_global_init(CURL_GLOBAL_ALL);
}

Translator::~Translator() { curl_global_cleanup(); }

std::string Translator::translate(const std::string &target_language,
                                  const std::vector<std::string> &texts) {
  std::string body = buildRequestBody(target_language, texts);
  std::string response_string;

  CURL *curl = curl_easy_init();
  if (curl) {
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    std::string auth_header = "Authorization: Bearer " + IAM_TOKEN;
    headers = curl_slist_append(headers, auth_header.c_str());

    curl_easy_setopt(
        curl, CURLOPT_URL,
        "https://translate.api.cloud.yandex.net/translate/v2/translate");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res)
                << std::endl;
    }

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
  }

  json jsonData = json::parse(response_string);
  return jsonData["translations"][0]["text"];
}

size_t Translator::WriteCallback(void *contents, size_t size, size_t nmemb,
                                 std::string *output) {
  size_t real_size = size * nmemb;
  output->append(static_cast<char *>(contents), real_size);
  return real_size;
}

std::string
Translator::buildRequestBody(const std::string &target_language,
                             const std::vector<std::string> &texts) {
  std::string body =
      "{\"targetLanguageCode\":\"" + target_language + "\",\"texts\":[";
  bool first_text = true;
  for (const auto &text : texts) {
    if (!first_text) {
      body += ",";
    } else {
      first_text = false;
    }
    body += "\"" + text + "\"";
  }
  body += "],\"folderId\":\"" + folder_id + "\"}";
  return body;
}
