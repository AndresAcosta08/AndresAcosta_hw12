adv_graph.png : AA_graph.py advection.txt
	python AA_graph.py
advection.txt : advection
	./advection > advection.txt
advection : AA_advection.cpp
	c++ AA_advection.cpp -o advection
