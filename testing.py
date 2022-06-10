import typer
import app_store_scrapper as appstore

app = typer.Typer()
store = appstore.app_store_scrapper("fr", "fr")



#APP _ details
@app.command()
def appdetails(app_id: int):
    store.appdetails(app_id)
    pass


#Fetch _ By _ developper
@app.command()
def fetch_by_developper(dev_str: str):
    store.fetch_by_developper(dev_str)
    pass


#Search
@app.command()
def search_app(key_word: str):
    store.search_app(key_word)
    pass



#Verify deletion status
@app.command()
def verify_deletion(app_id: int):
    store.verify_deletion(app_id)
    pass



#Verify if new version is out
@app.command()
def version_monitoring():
    store.version_monitoring()
    pass

if __name__ == "__main__":
    app()





