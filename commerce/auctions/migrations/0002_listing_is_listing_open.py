# Generated by Django 4.1.1 on 2022-11-03 12:47

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='listing',
            name='is_listing_open',
            field=models.BooleanField(default=True),
        ),
    ]