from pprint import pprint


class HtmlDocument:
    extension = 'html'
    version = '5'

    def render():
        print('Rendering the Html doc...')


pprint(HtmlDocument.__dict__)

