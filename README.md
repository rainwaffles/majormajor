This repository is the main thingy for avbotz controlling stuff (not to be confused with control)

there will be a set of goals (eg: hit red buoy, octagon, etc)
each goal will have a value (typically in number of points), a certainty (likelihood we can actually complete it), and how long it takes to complete (not factoring in distance)
we can also calculate distance from modeling
goal is selected to maximize: value * certainty / (time + distance * speed)
when goal is completed, it is removed from list
goal can be switched when moving towards a goal, but not when actually completing it

a goal consists of a sequence of actions
Actions:
	move to location relative to target's location based on modeling (eg move to 6 ft above bin, surface over pinger, etc)
		location can be expressed in a number of ways (eg: at these variables' coordinates, this distance past these coordinates (in whatever direction the sub is moving), etc)
	drop / shoot torpedo / grab / etc
	(we'll probably end up making more specific actions as necessary)

Examples:
	Buoys (different variables for each one):
		move 3 ft past coordinates given by the respective variables
	Octagon:
		move to depth of 10 ft at current x,y coordinates
		move to depth of 10 ft at coordinates of pinger
		move to depth of -10 ft at current x,y coordinates
		move to depth of 10 ft at current x,y coordinates
	Maneuvering:
		move 10 ft past coordinates given by respective variables with yaw pointed in other direction
	Dropper:
		move to depth of 10 ft at current x,y coordinates
		move to depth of 10 ft at coordinates of covered bin
		move to depth of 15 ft at current x,y coordinates
		grab
		move to depth of 10 ft at current x,y coordinates
		move forwards 5 ft
		release
		move back to bin
		drop
		move to other bin
		drop
	Torpedoes will require a lot of specific steps because of the precision required

we'll have to work out a convenient way to express those locations


mission control will be connected via 2 pipes (input / output) to a master interface that manages all data

Protocol:
	mission control sends
		<query> <arguments>
	the response varies with the query

Messages:
	c | command
	q | query

	Command Types:
		s | set desired state
		d | drop
		t | shoot torpedo
		g | grabber

	Query Types:
		s | state
		i | image
		v | vision
		u | ultrasonic
		m | modeling

Arguments:
	Commands:
		State:
			<yaw> <pitch> <roll> <depth> <x> <y>
		Dropper:
			<no arguments>
		Torpedo:
			r | right
			l | left
		Grabber:
			g | grab
			r | release
		
	Queries:
		Images:
			<direction> <resolution scale> <vertical crop> <horizontal crop>
			Direction:
				f | front
				d | down
			scale and crops are floating point numbers
			Response:
				<rows> <cols> <sequence of bytes>
		Vision:
			<task>
			Tasks:
				g | gate
				b | buoys
				m | maneuvering
				d | bins
				t | torpedoes
				h | hydrophones
			Response:
				<num values> <value 1> <value 2> ...
				values are floats
		Ultrasonic:
			<no arguments>
			Response:
				<distance>
		Modeling:
			<query>
			Query:
				s | entire system
				m | mode
				c | certainty
			Response:
				System:
					outputs a system object (see System.write in modeling)
				Mode:
					outputs a matrix object (see Matrix.write in modeling)
				Certainty:
					outputs a float from 0 to 1

