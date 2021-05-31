#from django.http import HttpResponse
# 
#def hello(request):
#    return HttpResponse("Hello World!")
from django.shortcuts import render
 
def hello(request):
    context          = {}
    context['hello'] = ['Hello Django!', 'Python']
    return render(request, 'runoob.html', context)

