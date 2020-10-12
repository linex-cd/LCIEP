#创建SocketServerTCP服务器：
import SocketServer
import time
import os
from SocketServer import StreamRequestHandler as SRH
from time import ctime

host = '127.0.0.1'
port = 9999
addr = (host,port)

def gettimestring():
	t = time.strftime('[%Y-%m-%d %H:%M:%S]',time.localtime(time.time()))
	return t
	
#读文件	
def read_file_content(filename):
	content = ""
	if os.path.exists(filename) == False:
		return content
		
	file_object = open(filename)
	try:
		content = file_object.read()
	finally:
		file_object.close()	
	return content
	
#写文件	
def write_file_content(filename, content):
	fp = file(filename, 'w')
	fp.write(content)
	fp.close()
	
	return content
	
def hello(param):
	ret = gettimestring()+"hello "+param+"!"
	print ret
	return ret

def debug(param):
	tag = param[param.find("-tag")+5:param.find("-msg")-1];
	msg = param[param.find("-msg")+5:];
	ret = gettimestring()+"["+tag+"]"+msg
	print ret
	return "ok"

def readfile(param):
	file = param[param.find("-file")+6:];
	content = read_file_content("./ZJFile/"+file)
	ret = gettimestring()+"[readfile]"+file
	print ret
	return content

def writefile(param):
	file = param[param.find("-file")+6:param.find("-text")-1];
	text = param[param.find("-text")+6:];

	write_file_content("./ZJFile/"+file, text)
	ret = gettimestring()+"[writefile]"+file
	print ret
	return "ok"	
	
def processcmd(data):

	cmd = data[1:data.find(" ")];
	param = data[data.find(" ")+1:];
	param = param.strip()
	if(cmd == "hello"):
		return hello(param)
	if(cmd == "debug"):
		return debug(param)
	if(cmd == "readfile"):
		return readfile(param)
	if(cmd == "writefile"):
		return writefile(param)

	return "bad command"

class Servers(SRH):
	def handle(self):
		#print 'got connection from ',self.client_address
		#self.wfile.write('connection %s:%s at %s succeed!' % (host,port,ctime()))
		
		while True:
			data = self.request.recv(1024)
			if not data:
				break
			#print "RECV from ", self.client_address[0]
			#print data
			
			ret = processcmd(data)
			if ret != "":
				self.wfile.write(ret)
			#self.request.send(data)
print 'server is running....'
server = SocketServer.ThreadingTCPServer(addr,Servers)
server.serve_forever()

