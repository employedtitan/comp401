from urllib2 import urlopen
import os
from json import loads

class wheathertracker(object):
    
    def __init__(self, city, file_name):
        #the key required to contact wunderground and retrive data
        self.key = 'f8430318bd5f6cb8' 
        #the requested city, preset will be Wheaton college/Norton but can be changed
        self.city = city
        #file the output will write the svg to
        self.file_name= file_name
        """
        self.wheaton = 'a'
	self.pic = 'a'
	self.temperature = 'a'
	self.condition = 'a'
	self.humidity = 'a'
	self.wind = 'a'
        """
    def dataretrive(self):
        
        obj = open(self.file_name, 'w')
        lookhere = urlopen('http://api.wunderground.com/api/%s/geolookup/conditions/q/MA/%s.json' % (self.key, self.city))
        
	data = lookhere.read()
        
        parsed = loads(data)
        
        location = parsed ['location']['city']
        pic = parsed['current_observation']['icon_url']
        wheaton = parsed['current_observation']['observation_location']['city']
        humidity = parsed['current_observation']['relative_humidity']
        condition = parsed['current_observation'] ['weather']
        wind = parsed['current_observation']['wind_string']
        temperature = parsed ['current_observation']['temp_f']
        
        
        lookhere.close()
        
        self.writesvg(location, pic, wheaton, humidity, condition, wind, temperature)
   
        
    def writesvg(self, location, pic, wheaton, humidity, condition, wind, temperature):
        
        obj = open(self.file_name, 'w')
        
        obj.write('<!DOCTYPE html> \n')
        obj.write('<html> \n')
        obj.write('<head> \n')
	obj.write('<link rel="stylesheet" type="text/css" href="mystyle.css"> \n')
	obj.write('<title>Wheaton College wheather</title> \n')
	obj.write('</head> \n')
	obj.write('<body> \n')
        obj.write('<div text-align="center"> \n')
	
	obj.write('<svg width = "1500" height = "1000" version = "1.1" xmlns="http://www.w3.org/2000/svg"> \n')
        
        obj.write('<text x = "200" y = "50" font-family = "Verdana" font-size = "55" fill = "black">Current wheather at %s </text> \n' %(wheaton)) 
	
	obj.write('<rect x = "550" y = "200" width="500" height="500" style="fill:rgb(0,0,255)";stroke-width:"150";stroke:"rgb(0,0,0)"; /> \n')
	
	obj.write('<text x = "550" y = "250" font-family = "Verdana" font-size = "35" fill = "white">%s</text> \n' % (wheaton))
	obj.write('<text x = "550" y = "325" font-family = "Verdana" font-size = "25" fill = "white">Condition: %s</text> \n' % (condition))
	obj.write('<image xlink:href="%s" x="700" y="500" height="150px" width="150px"/> \n' %(pic))
	obj.write('<text x = "550" y = "400" font-family = "Verdana" font-size = "25" fill = "white">Temperature: %s</text> \n' % (temperature))
	obj.write('<text x = "550" y = "465" font-family = "Verdana" font-size = "25" fill = "white">Humidity: %s</text> \n' % (humidity))
        obj.write('<text x = "550" y = "520" font-family = "Verdana" font-size = "15" fill = "white">Wind description: %s</text> \n' % (wind))
	
    def writecss(self, otrofile):
	
	obj = open(otrofile, 'w')
	
	obj.write("body{ background: rgb(215, 215, 215); background: -webkit-gradient(radial, 50% 50%, 0, 50% 50%, 500, from(rgb(240, 240, 240)), to(rgb(78, 100, 79))); background: -webkit-radial-gradient(rgb(240, 240, 240), rgb(78, 100, 79)); background:    -moz-radial-gradient(rgb(240, 240, 240), rgb(78, 100, 79)); background:     -ms-radial-gradient(rgb(240, 240, 240), rgb(78, 100, 79)); background:      -o-radial-gradient(rgb(240, 240, 240), rgb(78, 100, 79)); background:         radial-gradient(rgb(240, 240, 240), rgb(78, 100, 79));}")
	
	obj.close()
    
def main():
    
    city = 'Norton'
    
    file_name = 'trashboat.html'
    css = 'mystyle.css'
    apple = wheathertracker(city, file_name)
    
    apple.dataretrive()
    apple.writecss(css)

if (__name__ == '__main__'):
        
    main()
        
        