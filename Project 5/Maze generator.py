from random import shuffle, randrange, randint

class Maze(object):
	
	def __init__(self, width, height):
		#directional constants
		self.N = 0
		self.E = 1
		self.S = 2
		self.W = 3
		#Setting up the arrays to hold this maze
		self.vis = 0
		self.ver = 0
		self.hor = 0
		#making the height, width,  and file name available to the whole object
		self.width = width
		self.height = height
		self.svgy = 400
		self.svgx = 400
		self.mazey = 1
		self.mazex = 1
		self.smallerheight = 20
		
		self.border = 1
		
	
		#offsets for the direction changes while navigating to create the maze	
		self.listofoffsets = [ (0,-1), (1,0), (0, 1), (-1, 0)]
		
	def make_maze(self):
		
		#setting up the arrays to contain the maze itself
		self.wid = []
		for y in xrange(self.height+1):
			self.wid.append([])
			for x in xrange(self.width):
				self.wid[-1].append(True)

		self.hei = []
		for y in xrange(self.height):
			self.hei.append([])
			for x in xrange(self.width+1):
				self.hei[-1].append(True)
		
		#setting up the array to say which pieces have been visited	
		self.vis = []
		for y in xrange(self.height):
			self.vis.append([])
			for x in xrange(self.width):
				self.vis[-1].append(False)

 
	
		#Calling the function to navigate the arrays, creating the maze, will always start at the top left corner
		self.walk(0, 0)
		
		#create an end and a beginning to the maze
		
		thisone = randint(0,1)
		
		if thisone == 0:
			self.hei[0][0] = False
			self.hei[self.width - 1][self.height] = False
		
		if thisone == 1:
			self.wid[0][0] = False
			self.wid[self.width][self.height-1] = False

	def walk(self, x, y):
		
	
		self.vis[y][x] = True
		
		whichone = [self.N, self.E, self.S, self.W]

		shuffle(whichone)
		for dir in whichone:
			whichx = x +self.listofoffsets[dir][0]
			whichy = y +self.listofoffsets[dir][1]
			if whichx>= 0 and whichy>= 0 and whichx <= self.width-1 and whichy <= self.height-1 and not self.vis[whichy][whichx]:
				#if statements saying which walls to knock down
				if dir == self.N:
					self.wid[y][x] = False
					
				elif dir == self.S:
					self.wid[y+1][x] = False
					
				elif dir == self.W:
					self.hei[y][x] = False
				
				elif dir == self.E:
					self.hei[y][x+1] = False
			
				#recursive call to walk to say where to go next
				self.walk(whichx, whichy) 


	def coordinates(self, file_name):
		
		#opens user picked file name
		obj = open(file_name +'.svg', 'w')
		
		widths = self.svgx + 4 *2
		heights = self.svgy + 4 *2
		#writing the heading of the svg file
		obj.write('<?xml version="1.0" standalone="no"?>\n'
			'<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">\n'
			'\n')
		obj.write("<svg height = '%dcm' width = '%dcm' version = '1.1' xmlns='http://www.w3.org/2000/svg'>" % (heights, widths))
		obj.write("\n")
		#self.obj.write("<rect width = '%d' height = '%d' style = 'fill: none; stroke-width:4; stroke:rgb(0,0,0)'/>" %(adjht, adjwid)) 		
		#self.obj.write("\n")
		for x in xrange(self.width+1):
			inline = 0
			xplus = x * self.mazex
					
			#writing the y coordinates as svg lines
			for y in xrange(self.height):
						
				if inline == 0:
					if self.hei[y][x]:
						inline = 1
						y1 = y
							
				if inline == 1:
					if not self.hei[y][x] or y == self.height-1:
									
						if y == self.height - 1 and self.hei[y][x]:
							addition = 1
						else:
							addition = 0
						inline = 0
									
						y2 = y
						obj.write("<line x1 = '%dcm' y1 = '%dcm' x2 = '%dcm' y2 = '%dcm' style = 'stroke: black; stroke-width:2px; stroke-miterlimit:4; stroke-linecap:round' />" %(xplus, (y1 *self.mazey), xplus, ((y2 + addition)*self.mazey)))
						obj.write("\n")							
				
				#obj.write("<line x1 = '0' y1 = '", board.linestart[coloum],"' x2 = '0' y2 = '", board.lineend[coloum],"' style ='stroke:rgb(0,0,0);strokewidth:2' />")
		
		for y in xrange(self.height+1):
			#the coordinates are in line if 1 not in line if 0
			inline = 0
			#an adjustment for the final coordinates
			
			yplus = y * self.mazey
			#writing the x coorinates as svg lines
			for x in xrange(self.width):
				if inline == 0:
					#this is not in the line
					if self.wid[y][x] == 1:
						inline = 1
						x1 = x
				if inline == 1: 
					#is in line
					if not self.wid[y][x] or x==self.width-1:
						
						#case check for a bug that makes the lines be a bit off
						if x == self.width - 1 and self.wid[y][x]:
							
							addition = 1
						
						else:
							addition = 0
						
						inline = 0
						
						x2 = x
							
						obj.write("<line x1 = '%dcm' y1 = '%dcm' x2 = '%dcm' y2 = '%dcm' style = 'stroke: black; stroke-width:2px;s troke-miterlimit:4; stroke-linecap:round' />" %((x1 *self.mazex), yplus, ((x2+addition)* self.mazex), yplus))
						obj.write("\n")
		for x in xrange(self.width+1):
			inline = 0
			xplus = x * self.mazex
			
			#writing the y coordinates as svg lines
			for y in xrange(self.height):
				
				if inline == 0:
					if self.hei[y][x]:
						inline = 1
						y1 = y
					
					if inline == 1:
						if not self.hei[y][x] or y == self.height-1:
							
							if y == self.height - 1 and self.hei[y][x]:
								addition = 1
							else:
								addition = 0
							inline = 0
							
							y2 = y
							obj.write("<line x1 = '%dcm' y1 = '%dcm' x2 = '%dcm' y2 = '%dcm' style = 'stroke: black; stroke-width:2px; stroke-miterlimit:4; stroke-linecap:round' />" %(xplus, (y1 *self.heights), xplus, ((y2 + addition)*self.heights)))
							obj.write("\n")							
		
		#obj.write("<line x1 = '0' y1 = '", board.linestart[coloum],"' x2 = '0' y2 = '", board.lineend[coloum],"' style ='stroke:rgb(0,0,0);strokewidth:2' />")
    
		obj.write("</svg>")
		obj.close()		
    
	
def main():
	
	height = 40
	#input('Please enter the desired coloums of you maze: ')
	width = 40
	#input('Please enter the desired rows of your maze: ')	
	file_name = "outp"
	#input("Please enter the file name you'd wish to save to: ")
	
	maze = Maze(width, height)
	maze.make_maze()
	maze.coordinates(file_name)
	
	
	
	
if (__name__ == '__main__'):
	    
	main()	