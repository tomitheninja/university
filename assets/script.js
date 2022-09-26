// toggle between light and dark theme
const toggleSwitch = document.getElementById('checkbox');

function switchTheme(theme) {
  document.documentElement.setAttribute('data-theme', theme);
  localStorage.setItem('data-theme', theme);
  toggleSwitch.checked = theme === 'dark';
}

toggleSwitch.addEventListener('change', (e) => switchTheme(e.target.checked ? 'dark' : 'light'), false);

const prevTheme = localStorage.getItem('data-theme');
if (prevTheme) {
  switchTheme(prevTheme)
}

// generate table of contents
const main = document.getElementById('main_content')
if (main.children.length > 50)
{
  const arr = []
  for(let i = 0; i < main.children.length; i++)
  {
    const x = main.children[i];
    if (x.tagName == 'H2') arr.push({title: x.innerText, id: x.id, children: []})
    if (x.tagName == 'H3') arr[arr.length - 1].children.push( {title: x.innerText, id: x.id} )
  }
  main.innerHTML = `
  <div id="tableofcontents">
  <h1>📝 Table Of Contents</h1>
  <ul>
  ${arr.map(h1 =>
    `<li>
    <a href="#${h1.id}">${h1.title}</a>
    <ul>${h1.children.map(h2 => `<li><a href="#${h2.id}">${h2.title}</a></li>`).join('')}</ul>
    </li>`).join('')}
    </ul>
    </div>` + main.innerHTML
  }
