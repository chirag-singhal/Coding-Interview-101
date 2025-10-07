# 📘 OkHttp3 Usage Notes & Examples (Java)

A quick reference for common scenarios using [OkHttp3](https://square.github.io/okhttp/) in Java.

---

## ✅ 1. Synchronous GET Request

```java
OkHttpClient client = new OkHttpClient();
Request request = new Request.Builder()
    .url("https://api.example.com/data")
    .build();

try (Response response = client.newCall(request).execute()) {
    System.out.println(response.body().string());
}
````

---

## ✅ 2. Asynchronous GET Request

```java
OkHttpClient client = new OkHttpClient();
Request request = new Request.Builder()
    .url("https://api.example.com/data")
    .build();

client.newCall(request).enqueue(new Callback() {
    @Override
    public void onFailure(Call call, IOException e) {
        e.printStackTrace();
    }

    @Override
    public void onResponse(Call call, Response response) throws IOException {
        if (response.isSuccessful()) {
            System.out.println(response.body().string());
        }
    }
});
```

---

## ✅ 3. GET with URL Query Parameters

```java
HttpUrl url = HttpUrl.parse("https://api.example.com/search")
    .newBuilder()
    .addQueryParameter("q", "okhttp")
    .addQueryParameter("page", "1")
    .build();

Request request = new Request.Builder()
    .url(url)
    .build();
```

---

## ✅ 4. POST with JSON Body (From String)

```java
MediaType JSON = MediaType.get("application/json; charset=utf-8");
String json = "{\"name\":\"John\", \"age\":30}";

RequestBody body = RequestBody.create(json, JSON);
Request request = new Request.Builder()
    .url("https://api.example.com/users")
    .post(body)
    .build();
```

---

## ✅ 5. POST with JSON Body (From File)

```java
File jsonFile = new File("path/to/data.json");
MediaType JSON = MediaType.get("application/json; charset=utf-8");

RequestBody body = RequestBody.create(jsonFile, JSON);
Request request = new Request.Builder()
    .url("https://api.example.com/users")
    .post(body)
    .build();
```

---

## ✅ 6. POST with Form Body (`application/x-www-form-urlencoded`)

```java
RequestBody formBody = new FormBody.Builder()
    .add("username", "john")
    .add("password", "secret")
    .build();

Request request = new Request.Builder()
    .url("https://api.example.com/login")
    .post(formBody)
    .build();
```

---

## ✅ 7. POST Multipart (e.g. File Upload + Text)

```java
File file = new File("path/to/file.jpg");
MediaType MEDIA_TYPE_JPG = MediaType.get("image/jpeg");

RequestBody requestBody = new MultipartBody.Builder()
    .setType(MultipartBody.FORM)
    .addFormDataPart("description", "Profile photo")
    .addFormDataPart("file", file.getName(),
        RequestBody.create(file, MEDIA_TYPE_JPG))
    .build();

Request request = new Request.Builder()
    .url("https://api.example.com/upload")
    .post(requestBody)
    .build();
```

---

## ✅ 8. Add Headers (Authorization, Content-Type, etc.)

```java
Request request = new Request.Builder()
    .url("https://api.example.com/protected")
    .addHeader("Authorization", "Bearer your_token_here")
    .addHeader("Custom-Header", "value")
    .build();
```

---

## ✅ 9. Download File and Save to Disk (Simple)

```java
ResponseBody body = response.body();
InputStream inputStream = body.byteStream();
FileOutputStream fos = new FileOutputStream("file.pdf");

// Copy inputStream to outputStream

 Path filePath = Paths.get(targetPath + File.separator + filename);

OutputStream output = new FileOutputStream(filePath.toFile());
InputStream stream = response.body().byteStream();
stream.transferTo(output);
output.close();
stream.close();
```

---

## ✅ 10. 🔄 Download File and Get File Name + Extension from Headers

```java
public void downloadFileWithFilename(String fileUrl, String saveDir) throws IOException {
    OkHttpClient client = new OkHttpClient();
    Request request = new Request.Builder().url(fileUrl).build();

    try (Response response = client.newCall(request).execute()) {
        if (!response.isSuccessful()) throw new IOException("Failed: " + response);

        // Try to extract filename from Content-Disposition header
        String disposition = response.header("Content-Disposition");
        String fileName = null;

        if (disposition != null) {
            Pattern pattern = Pattern.compile("filename=\"?([^\";]+)\"?");
            Matcher matcher = pattern.matcher(disposition);
            if (matcher.find()) {
                fileName = matcher.group(1);
            }
        }

        // Fallback to last part of URL
        if (fileName == null) {
            fileName = fileUrl.substring(fileUrl.lastIndexOf("/") + 1);
        }

        // Save to disk
        File outputFile = new File(saveDir, fileName);
        try (InputStream in = response.body().byteStream();
             FileOutputStream out = new FileOutputStream(outputFile)) {

            byte[] buffer = new byte[4096];
            int len;
            while ((len = in.read(buffer)) != -1) {
                out.write(buffer, 0, len);
            }
        }

        System.out.println("Downloaded: " + outputFile.getAbsolutePath());
    }
}
```

---

## ✅ 11. Set Timeouts

```java
OkHttpClient client = new OkHttpClient.Builder()
    .connectTimeout(10, TimeUnit.SECONDS)
    .writeTimeout(30, TimeUnit.SECONDS)
    .readTimeout(30, TimeUnit.SECONDS)
    .build();
```

---

## ✅ 12. Retry on Failure

```java
OkHttpClient client = new OkHttpClient.Builder()
    .retryOnConnectionFailure(true)
    .build();
```

---

## ✅ 13. Add Logging Interceptor

```java
HttpLoggingInterceptor logging = new HttpLoggingInterceptor();
logging.setLevel(HttpLoggingInterceptor.Level.BODY);

OkHttpClient client = new OkHttpClient.Builder()
    .addInterceptor(logging)
    .build();
```

> Maven dependency:

```xml
<dependency>
    <groupId>com.squareup.okhttp3</groupId>
    <artifactId>logging-interceptor</artifactId>
    <version>4.12.0</version>
</dependency>
```

---

## ✅ 14. Follow Redirects

```java
OkHttpClient client = new OkHttpClient.Builder()
    .followRedirects(true)
    .followSslRedirects(true)
    .build();
```

---

## ✅ 15. Cancel Ongoing Request

```java
Call call = client.newCall(request);
call.cancel(); // Call this to cancel the request
```

---

## ✅ 16. Add Query Parameters Dynamically

```java
String baseUrl = "https://api.example.com/search";
Map<String, String> queryParams = Map.of("q", "search", "lang", "en");

HttpUrl.Builder urlBuilder = HttpUrl.parse(baseUrl).newBuilder();
queryParams.forEach(urlBuilder::addQueryParameter);

HttpUrl fullUrl = urlBuilder.build();
Request request = new Request.Builder().url(fullUrl).build();
```

---


