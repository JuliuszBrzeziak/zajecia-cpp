from django.urls import path
from . import views

urlpatterns = [
    path('wpisy_list', views.wpisy_list),
]
