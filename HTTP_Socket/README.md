## Test for serving and fetching data using sockets in C

<br>
<br>




Sets up socket for client and server.
First download the folder, navigate to it, open the terminal there and type **make**
Then you can either run as client or server by typing:

**./HTTPClient <EXAMPLE_OF_IP_ADDRESS>**
Example: ./HTTPClient 172.217.22.174
Where the IP address specified can be any IP address. Can be found by typing "ping google.com" for example
Will fetch the status from fetching the page and the page body

**./HTTPServer**
Will start a server which serves a webpage, localhost:8001 to the web
