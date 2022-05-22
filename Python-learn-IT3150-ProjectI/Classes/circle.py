class Circle:
    circle_list = []
    pi = 3.14159

    def __init__(self, radius):
        self.radius = radius
        # add the instance to the circle list
        self.circle_list.append(self)

    def area(self):
        return self.pi * self.radius**2

    def circumference(self):
        return 2 * self.pi * self.radius