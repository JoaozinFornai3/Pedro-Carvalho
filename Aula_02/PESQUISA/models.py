from django.db import models

class Question(models.Model):
    question_text = models.Charfield(max_length=200)
    pub_date = models.DateTimeField("date published")

class Choise(models.Model):
    questions = models.ForeignKey(Question, on_delete=models.CASCADE)
    choice_text = models.Charfield(max_length=200)
    votes = models.IntegerField(default=0)