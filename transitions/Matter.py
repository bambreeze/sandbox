from transitions.extensions import GraphMachine as Machine

class Matter(object):
    pass

    def draw(self):
        # draw the whole graph ...
        self.get_graph().draw('matter_state_diagram.png', prog='dot')

    def roi(self, name):
        # ... or just the region of interest
        # (previous state, active state and all reachable states)
        roi = self.get_graph(show_roi=True).draw(name + '.png', prog='dot')

model = Matter()

#The states argument defines the name of states
states=['solid', 'liquid', 'gas', 'plasma']

# The trigger argument defines the name of the new triggering method
transitions = [
    {'trigger': 'melt', 'source': 'solid', 'dest': 'liquid' },
    {'trigger': 'evaporate', 'source': 'liquid', 'dest': 'gas'},
    {'trigger': 'sublimate', 'source': 'solid', 'dest': 'gas'},
    {'trigger': 'ionize', 'source': 'gas', 'dest': 'plasma'}]

machine = Machine(model=model, states=states, transitions=transitions, initial='solid')

# Test
model.draw()
model.roi('init')

print(model.state)  # solid
model.roi('solid')

model.melt()
print(model.state)  # liquid
model.roi('liquid')

model.evaporate()
print(model.state)  # gas
model.roi('gas')
