# HTTP1.0 client/server

In the main directory, run

```
cmake .
```

Then, run

```
make
```

With a terminal opened, make the server up

```
./web-server localhost 4000 /tmp
```

## Test: 200 - OK

Use that server with a client

```
./web-client "http://localhost:4000/index.html
```

By doing that, you will get

```
IP addresses for localhost: 
  127.0.0.1
Set up a connection from: 127.0.0.1:34910

GET/index.html
Salva arquivo em ./Client/tmp/index.html

status: 200 - OK
payload: <html>

<head>
</head>

<body>

    <h1> This is a just an example</h1>

</body>
</html>
```

## Test: 404 - Not Found

Use that server with a client

```
./web-client "http://localhost:4000/index.htm
```

By doing that, you will get

```
IP addresses for localhost: 
  127.0.0.1
Set up a connection from: 127.0.0.1:35078

GET/index.htm
status: 404 - Not Found
payload:
```

## Test: 400 - Bad Request

Use that server with a client

```
./web-client "http://localhost:4000/index
```

By doing that, you will get

```
IP addresses for localhost: 
  127.0.0.1
Set up a connection from: 127.0.0.1:35246

GET/inde.
status: 400 - Bad Request
payload: 
```


