( for F in trump_tweets_0?.csv ; do cat $F | ./mapper.py ; done ) | sort | ./reducer.py
