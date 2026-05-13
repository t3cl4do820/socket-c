client=client/client_comments.c
client_bin=client
server=server/server_comments.c
server_bin=server
dict_outPut=build

server_c:
	gcc $(server) -o $(dict_outPut)/$(server_bin) && ./$(dict_outPut)/$(server_bin)

client_c:
	gcc $(client) -o$(dict_outPut)/$(client_bin) && ./$(dict_outPut)/$(client_bin)
