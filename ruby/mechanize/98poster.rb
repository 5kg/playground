# encoding: UTF-8

require 'mechanize'

bot = Mechanize.new

login_page = bot.get 'http://www.cc98.org/login.asp'
login_form = login_page.form_with :id => 'loginForm'
login_form.username = 'username'
login_form.password = 'password'
login_form.submit

posts = %w{http://www.cc98.org/dispbbs.asp?boardID=xx&ID=xxxxxxx http://www.cc98.org/dispbbs.asp?boardID=xx&ID=xxxxxxxx}
replies = %w{Foo Bar Baz}

while true
  post = posts.sample
  page = bot.get post
  form = page.form_with :name => 'frmAnnounce'
  form.Content = replies.sample
  form.submit
  sleep 1800 + Random.rand(200)
end
