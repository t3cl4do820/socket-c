client=client/client.c
client_bin=client
server=server/server.c
server_bin=server
dict_outPut=build

server_c:
	gcc $(server) include/socketutils.c -I../include -o $(dict_outPut)/$(server_bin) && ./$(dict_outPut)/$(server_bin)

client_c:
	gcc $(client) include/socketutils.c -I../include -o $(dict_outPut)/$(client_bin) && ./$(dict_outPut)/$(client_bin)
